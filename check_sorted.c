/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:01:23 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/10 17:58:50 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted_sort_3_1(t_data data, int pos, int nums)
{
}

static int	is_sorted_sort_3_2(t_data data, int pos)
{
}

int	is_sorted_sort_3(t_data data, int pos)
{
	int		num1;
	int		num2;
	int		num3;
	t_node	*start_node;

	start_node = get_start_node(data, pos);
	num1 = start_node->content;
	start_node = get_next_node(start_node, pos);
	num2 = start_node->content;
	start_node = get_next_node(start_node, pos);
	num3 = start_node->content;
	if (pos == A_BTM && (num1 < num2 && num1 < num3))
	{
		sort_2(data, A_TOP);
		execute_append(data, rra);
	}
	else if (pos == A_BTM && (num3 > num1 && num3 > num2))
	{
		execute_append(data, ra);
		sort_2(data, A_TOP);
	}
	else if ((pos == A_BTM && (num1 > num2 && num1 > num3)) || \
			(pos == A_TOP && (num3 > num1 && num3 > num2)))
		sort_2(data, A_TOP);
	else if ((pos == A_BTM && (num3 < num1 && num3 < num2)) || \
			(pos == A_TOP && (num1 < num2 && num1 < num3)))
	{
		if ((pos == A_TOP && (num2 > num3)) || \
				(pos == A_BTM && (num1 < num2)))
		{
			execute_append(data, ra);
			sort_2(data, A_TOP);
			execute_append(data, rra);
		}
	}
	else if ((num1 > num2 && num1 > num3) && (pos == B_TOP || pos == B_BTM))
	{
		move_to_iter(data, 3, pos, &move_to_a_top);
		sort_2(data, A_TOP);
	}
	else if ((num3 < num1 && num3 < num2) && (pos == B_TOP || pos == B_BTM))
	{
		move_to_iter(data, 2, pos, &move_to_a_top);
		sort_2(data, A_TOP);
		move_to_a_top(data, pos);
	}
	else
		return (0);
	return (-1);
}

int	is_sorted_sort_4(t_data data, int pos)
{
	int		i;
	int		flag;
	int		nums[4];
	t_node	*start_node;

	i = 0;
	flag = 0;
	start_node = get_start_node(data, pos);
	while (i < 4)
	{
		nums[i++] = start_node->content;
		start_node = get_next_node(start_node, pos);
	}
	if ((pos == A_TOP) && \
			(nums[0] < nums[1] && nums[1] < nums[2] && nums[2] < nums[3]))
		flag = -1;
	else if ((pos != A_TOP) && \
		(nums[0] > nums[1] && nums[1] > nums[2] && nums[2] > nums[3]))
		flag = -1;
	if (flag && (pos == B_TOP || pos == B_BTM))
		move_to_iter(data, 4, pos, &move_to_a_top);
	return (flag);
}

int	is_sorted(t_data data)
{
	t_node	*start_node;

	start_node = data.stack[0]->head;
	while (start_node->next)
	{
		if (start_node->content < start_node->next->content)
			return (0);
		start_node = start_node->next;
	}
	return (1);
}
