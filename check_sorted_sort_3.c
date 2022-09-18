/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted_sort_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:29:19 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/18 18:40:35 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted_sort_3_1(t_data data, int pos, int nums[])
{
	if (pos == A_BTM && (nums[0] < nums[1] && nums[0] < nums[2]))
	{
		sort_2(data, A_TOP);
		execute_append(data, rra);
		return (-1);
	}
	else if (pos == A_BTM && (nums[2] > nums[0] && nums[2] > nums[1]))
	{
		execute_append(data, ra);
		sort_2(data, A_TOP);
		return (-1);
	}
	else
		return (0);
}

static int	is_sorted_sort_3_2(t_data data, int pos, int nums[])
{
	if ((pos == A_BTM && (nums[0] > nums[1] && nums[0] > nums[2])) || \
			(pos == A_TOP && (nums[2] > nums[0] && nums[2] > nums[1])))
		sort_2(data, A_TOP);
	else if ((pos == A_BTM && (nums[2] < nums[0] && nums[2] < nums[1])) || \
			(pos == A_TOP && (nums[0] < nums[1] && nums[0] < nums[2])))
	{
		if ((pos == A_TOP && (nums[1] > nums[2])) || \
				(pos == A_BTM && (nums[0] < nums[1])))
		{
			if (pos == A_BTM)
			{
				execute_append(data, sa);
				execute_append(data, ra);
			}
			else
			{
				execute_append(data, ra);
				sort_2(data, A_TOP);
				execute_append(data, rra);
			}
		}
	}
	else
		return (0);
	return (-1);
}

static int	is_sorted_sort_3_3(t_data data, int pos, int nums[])
{
	if ((nums[0] > nums[1] && nums[0] > nums[2]) \
			&& (pos == B_TOP || pos == B_BTM))
	{
		move_to_iter(data, 3, pos, &move_to_a_top);
		sort_2(data, A_TOP);
	}
	else if ((nums[2] < nums[0] && nums[2] < nums[1]) \
			&& (pos == B_TOP || pos == B_BTM))
	{
		move_to_iter(data, 2, pos, &move_to_a_top);
		sort_2(data, A_TOP);
		move_to_a_top(data, pos);
	}
	else
		return (0);
	return (-1);
}

int	is_sorted_sort_3(t_data data, int pos)
{
	int		i;
	int		nums[3];
	t_node	*start_node;

	i = 0;
	start_node = get_start_node(data, pos);
	while (i < 3)
	{
		nums[i++] = start_node->content;
		start_node = get_next_node(start_node, pos);
	}
	if (is_sorted_sort_3_1(data, pos, nums) == -1)
		return (-1);
	if (is_sorted_sort_3_2(data, pos, nums) == -1)
		return (-1);
	return (is_sorted_sort_3_3(data, pos, nums));
}
