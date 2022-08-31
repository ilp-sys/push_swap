/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/31 14:57:23 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a_top(t_data data, int pos, size_t *cnt)
{
	if (pos % 3 == 1)
	{
		operation_reverse_rotate(data.stack[0]);
		append_to_ops(data.ops, rra);
	}
	else if (pos % 3 == 2)
	{
		operation_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
	}
	else
	{
		operation_reverse_rotate(data.stack[1]);
		append_to_ops(data.ops, rrb);
		operaion_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
	}
}

void	move_to_b_top(t_data data, int pos, size_t *cnt)
{
	if (pos % 3 == 1)
	{
		operation_reverse_rotate(data.stack[0]);
		append_to_ops(data.ops, rra);
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
	}
	else if (pos % 3 == 2) //move to A btm tentatively
	{ 
		opreation_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
		operation_rotate(data.stack[0]);
		append_to_ops(data.ops, ra);
		(*cnt)++;
	}
	else 
	{
		operation_reverse_rotate(data.stack[1]);
		append_to_ops(data.ops, rrb);
	}
}

void	move_to_b_btm(t_data data, int pos, size_t *cnt)
{
	if (pos % 3 == 1)
	{
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
		operation_rotate(data.stack[1]);
		append_to_ops(data.ops, rb);
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
		(*cnt)++;
	}
}

void	collect(t_data data, int pos, size_t cnt)
{
	t_node	*start_node;

	start_node = data.stack[0].head;
	while (cnt--)
	{
		operation_reverse_rotate(data.stack[0]);
		append_to_ops(data.ops, rra);
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
		if (pos % 3 == 0)
		{
			operation_roatate(data.stack[1]);
			append_to_ops(data.ops, rb);
		}
		start_node = start_node->next;
	}
}

t_pair	partitioning(t_data data, size_t low, size_t high, int *pos)
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
		if (start_node->content < pivot_v.former)
		{
			part_i.former++;
			move_to_a_top(data, pos, &cnt); //biggers
		}
		else if (start_node->content >= pivot_v.former && start_node->content <= pivot_v.latter)
			move_to_b_top(data, pos, &cnt); //medians
		else
		{
			part_i.latter++;
			move_to_b_btm(data, pos, &cnt); //smallers
		}
		start_node = get_next_node(start_node, pos);
	}
	collect(data, pos, cnt);
	*pos = 1;
	return (part_i);
}

void	quick_sort(t_data data, size_t low, size_t high, int *pos)
{
	int		tmp_pos;
	t_pair	pi;

	if (high - low <= 3)
	{
		sort_small_num(data, high, low, pos);
		(*pos)++;
		return ;
	}
	else
	{
		tmp_pos = *pos;
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

	pos = 1;
	init_data(data);
	size = get_queue_size(stack_a);
	quick_sort(data, 0, size, &pos);
}
