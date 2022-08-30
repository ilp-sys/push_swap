/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/30 16:05:11 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//TODO - clarify position var
void	move_to_other_bottom(t_data data, int pos)
{
	operation_push(data.stack[pos], data.stack[!pos]);
	if (pos)
		append_to_ops(data.ops, pa);
	else
		append_to_ops(data.ops, pb);
	operation_rotate(data.stack[!pos]);
	if (pos)
		append_to_ops(data.ops, ra);
	else
		append_to_ops(data.ops, rb);
}

void	move_to_other_top(t_data data, int pos)
{
	operation_reverse_rotate(data.stack[pos]);
	if (pos)
		append_to_ops(data.ops, rrb);
	else
		append_to_ops(data.ops, rra);
	operation_push(data.stack[pos], data.stack[!pos]);
	if (pos)
		append_to_ops(data.ops, pa);
	else
		append_to_ops(data.ops, pb);
}

void	move_to_here_top(t_data data, int pos)
{
	operation_reverse_rotate(data.stack[pos]);
	if (pos)
		append_to_ops(data.ops, rrb);
	else
		append_to_ops(data.ops, rra);
}

t_pair	partitioning(t_data data, size_t low, size_t high, int *pos)
{
	t_pair	part_i[2];
	t_pair	pivot_v[2];
	t_node	*start_node;

	part_i.former = low;
	part_i.latter = high;
	start_node = get_start_node(data, pos);
	pivot_v = find_pivot(start_node, low, high, pos);
	while (high > low++)
	{
		if (start_node->content < pivot_v.former)
			move_to_other_bottom(data, pos);
		else if (start_node->content >= pivot_v.former && start_node->content <= pivot_v.latter)
			move_to_other_top(data, pos);
		else
			move_to_here_top(data, pos);
	}
	*pos = 0;
	return (part_i);
}

void	quick_sort(t_data data, size_t low, size_t high, int *pos)
{
	int		tmp_pos;
	t_pair	pi;

	if (high - low <= 3)
	{
		sort_small_num(data, high, low, pos);
		(*pos)++; //TODO - tweak sequence
		return ;
	}
	else
	{
		tmp_pos = pos;
		pi = partitioning(data, high, low, &pos);
		quick_sort(data, low, pi.former, pos);
		quick_sort(data, pi.former, pi.latter, pos);
		quick_sort(data, pi.latter, high, pos);
	}
	*pos = tmp_pos;
}

void	push_swap(t_deq *stack_a, t_deq *stack_b, t_deq *ops)
{
	size_t	size;
	t_data	data;
	int		pos;

	pos = 0;
	init_data(data);
	size = get_queue_size(stack_a);
	quick_sort(data, 0, size);
}
