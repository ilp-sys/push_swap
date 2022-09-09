/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:01:23 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 21:38:02 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		operation_reverse_rotate(data.stack[0]);
		append_to_ops(data.ops, rra);
		return (-1);
	}
	else if (pos == A_BTM && (num3 > num1 && num3 > num2))
	{
		operation_rotate(data.stack[0]);
		append_to_ops(data.ops, ra);
		sort_2(data, A_TOP);
		return (-1);
	}
	else if (pos == A_BTM && (num1 > num2 && num1 > num3) || \
			pos == A_TOP && (num3 > num1 && num3 > num2))
	{
		sort_2(data, A_TOP);
		return (-1);
	}
	else if (pos == A_BTM && (num3 < num1 && num3 < num2) || \
			pos == A_TOP && (num1 < num2 && num1 < num3))
	{
		if (pos == A_TOP && (num2 > num3) || \
				pos == A_BTM && (num1 < num2))
		{
			operation_rotate(data.stack[0]);
			append_to_ops(data.ops, ra);
			sort_2(data, A_TOP);
			operation_reverse_rotate(data.stack[0]);
			append_to_ops(data.ops, rra);
		}
		return (-1);
	}
	else if ((num1 > num2 && num1 > num3) && (pos == B_TOP || pos == B_BTM))
	{
		move_to_a_top(data, pos);
		move_to_a_top(data, pos);
		move_to_a_top(data, pos);
		sort_2(data, A_TOP);
		return (-1);
	}
	else if ((num3 < num1 && num3 < num2) && (pos == B_TOP || pos == B_BTM))
	{
		move_to_a_top(data, pos);
		move_to_a_top(data, pos);
		sort_2(data, A_TOP);
		move_to_a_top(data, pos);
		return (-1);
	}
	else
		return (0);
}

int	is_sorted_sort_4(t_data data, int pos)
{
	int		i;
	t_node	*start_node;
	int		nums[4];

	i = 0;
	start_node = get_start_node(data, pos);
	while (i < 4)
	{
		nums[i++] = start_node->content;
		start_node = get_next_node(start_node, pos);
	}
	if ((pos == A_TOP) && \
			(nums[0] < nums[1] && nums[1] < nums[2] && nums[2] < nums[3]))
		return (-1);
	else if ((pos != A_TOP) && \
		(nums[0] > nums[1] && nums[1] > nums[2] && nums[2] > nums[3]))
		return (-1);
	return (0);
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
