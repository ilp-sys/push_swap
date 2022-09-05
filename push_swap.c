/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/05 15:44:18 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


size_t	move_to_a_top(t_data data, int pos)
{
	if (pos % 3 == 1)
	{
		if (get_queue_size(data.stack[0]) != 1)
		{
			operation_reverse_rotate(data.stack[0]);
			append_to_ops(data.ops, rra);
		}
	}
	else if (pos % 3 == 2)
	{
		operation_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
	}
	else
	{
		if (get_queue_size(data.stack[1]) != 1)
		{
			operation_reverse_rotate(data.stack[1]);
			append_to_ops(data.ops, rrb);
		}
		operation_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
	}
	return (0);
}

size_t	move_to_b_top(t_data data, int pos)
{
	size_t	cnt;

	cnt = 0;
	if (pos % 3 == 1)
	{
		operation_reverse_rotate(data.stack[0]);
		append_to_ops(data.ops, rra);
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
	}
	else if (pos % 3 == 2) //move to A btm tentatively
	{ 
		operation_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
		operation_rotate(data.stack[0]);
		append_to_ops(data.ops, ra);
		cnt++;
	}
	else 
	{
		operation_reverse_rotate(data.stack[1]);
		append_to_ops(data.ops, rrb);
	}
	return (cnt);
}

size_t	move_to_b_btm(t_data data, int pos)
{
	size_t	cnt;

	cnt = 0;
	if (pos % 3 == 1)
	{
		if (get_queue_size(data.stack[0]) != 1)
		{
			operation_reverse_rotate(data.stack[0]);
			append_to_ops(data.ops, rra);
		}
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
		if (get_queue_size(data.stack[1]) != 1)
		{
			operation_rotate(data.stack[1]);
			append_to_ops(data.ops, rb);
		}
	}
	else if (pos % 3 == 2)
	{
		operation_rotate(data.stack[1]);
		append_to_ops(data.ops, rb);
	}
	else //move to A btm tentatively
	{
		operation_reverse_rotate(data.stack[1]);
		append_to_ops(data.ops, rrb);
		operation_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
		operation_rotate(data.stack[0]);
		append_to_ops(data.ops, ra);
		cnt++;
	}
	return (cnt);
}

void	collect(t_data data, int pos, size_t cnt)
{
	t_node	*start_node;

	while (cnt--)
	{
		start_node = data.stack[0]->head;
		operation_reverse_rotate(data.stack[0]);
		append_to_ops(data.ops, rra);
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
		if (pos % 3 == 0)
		{
			operation_rotate(data.stack[1]);
			append_to_ops(data.ops, rb);
		}
	}
}

/*
t_pair	partitioning(t_data data, size_t low, size_t high, int *pos)
{
	size_t	cnt;
	t_pair	part_i;
	t_pair	pivot_v;
	t_node	*start_node;

	cnt = 0;
	part_i.former = low;
	part_i.latter = high;
	start_node = get_start_node(data, *pos);
	pivot_v = find_pivot(start_node, low, high, *pos);
	while (high > low++)
	{
		start_node = get_start_node(data, *pos);
		if (start_node->content < pivot_v.former)
		{
			part_i.former++;
			cnt += move_to_b_btm(data, *pos); //smallers
		}
		else if (start_node->content >= pivot_v.former && start_node->content <= pivot_v.latter)
			cnt += move_to_b_top(data, *pos); //medians
		else
		{
			part_i.latter--;
			cnt += move_to_a_top(data, *pos); //biggers
		}
	}
	if (cnt)
		collect(data, *pos, cnt);
	*pos = 1;
	return (part_i);
}

void	quick_sort(t_data data, size_t low, size_t high, int *pos)
{
	int		tmp_pos;
	t_pair	pi;

	if (high - low <= 3)
	{
		sort_small_num(data, high, low, *pos);
		(*pos)++;
		return ;
	}
	else
	{
		tmp_pos = *pos;
		pi = partitioning(data, low, high, pos);
		quick_sort(data, pi.latter, high, pos);
		quick_sort(data, pi.former, pi.latter, pos);
		quick_sort(data, low, pi.former, pos);
	}
	*pos = tmp_pos;
}

void	push_swap(t_deq *stack_a, t_deq *stack_b, t_deq *ops)
{
	size_t	size;
	t_data	data;
	int		pos;

	pos = 1;
	data = init_data(stack_a, stack_b, ops);
	size = get_queue_size(stack_a);
	quick_sort(data, 0, size, &pos);
}
*/

t_pair	partitioning(t_data data, size_t low, size_t high, int pos)
{
	size_t	cnt;
	t_pair	part_i;
	t_pair	pivot_v;
	t_node	*start_node;

	cnt = 0;
	part_i.former = low;
	part_i.latter = high;
	start_node = get_start_node(data, pos);
	pivot_v = find_pivot(start_node, low, high, pos);
	while (high > low++)
	{
		start_node = get_start_node(data, pos);
		if (start_node->content < pivot_v.former)
		{
			part_i.former++;
			cnt += move_to_b_btm(data, pos); //smallers
		}
		else if (start_node->content >= pivot_v.former && start_node->content <= pivot_v.latter)
			cnt += move_to_b_top(data, pos); //medians
		else
		{
			part_i.latter--;
			cnt += move_to_a_top(data, pos); //biggers
		}
	}
	if (cnt)
		collect(data, pos, cnt);
	return (part_i);
}

void	quick_sort(t_data data, size_t low, size_t high, int pos)
{
	t_pair	pi;

	if (high - low <= 3)
	{
		sort_small_num(data, high, low, pos);
		return ;
	}
	else
	{
		pi = partitioning(data, low, high, pos);
		quick_sort(data, pi.latter, high, 1);
		quick_sort(data, pi.former, pi.latter, 2);
		quick_sort(data, low, pi.former, 3);
	}
}

void	push_swap(t_deq *stack_a, t_deq *stack_b, t_deq *ops)
{
	size_t	size;
	t_data	data;

	data = init_data(stack_a, stack_b, ops);
	size = get_queue_size(stack_a);
	quick_sort(data, 0, size, 1);
}
