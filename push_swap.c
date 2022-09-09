/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 16:06:56 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	collect(t_data data, int pos, size_t cnt)
{
	t_node	*start_node;

	while (cnt--)
	{
		start_node = data.stack[0]->head;
		if (get_queue_size(data.stack[0]) != 1)
		{
			operation_reverse_rotate(data.stack[0]);
			append_to_ops(data.ops, rra);
		}
		if (pos == 1)
			continue ;
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
		if (pos % 3 == 0)
		{
			operation_rotate(data.stack[1]);
			append_to_ops(data.ops, rb);
		}
	}
}

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
	//printf("[partitioning] (%d) %zu %zu | %d %d\n", pos, low, high, pivot_v.former, pivot_v.latter);
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
	//print_queue(data.stack[0]);
	//print_queue(data.stack[1]);
	//printf("-------------------------\n");
	return (part_i);
}

void	quick_sort(t_data data, size_t low, size_t high, int pos)
{
	t_pair	pi;

	if (high - low <= 4)
	{
		//printf("[sort_samll] (%d) %zu %zu\n", pos, low, high);
		sort_small_num(data, high, low, pos);
		//print_queue(data.stack[0]);
		//print_queue(data.stack[1]);
		//printf("-------------------------\n");
		return ;
	}
	else
	{
		pi = partitioning(data, low, high, pos);
		quick_sort(data, pi.latter, high, A_TOP);
		quick_sort(data, pi.former, pi.latter, B_TOP);
		quick_sort(data, low, pi.former, B_BTM);
	}
}

void	push_swap(t_deq *stack_a, t_deq *stack_b, t_deq *ops)
{
	size_t	size;
	t_data	data;

	data = init_data(stack_a, stack_b, ops);
	size = get_queue_size(stack_a);
	if (size == 1 || is_sorted(data))
		return ;
	quick_sort(data, 0, size, A_BTM);
}
