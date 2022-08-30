/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/30 22:01:45 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_a_top(t_data, int pos)
{
	if (pos % 3 == 1)
		;
	else if (pos % 3 == 2)
		;
	else
		;
}

void	move_to_b_top(t_data, int pos)
{
	if (pos % 3 == 1)
		;
	else if (pos % 3 == 2)
		;
	else
		;
}

void	move_to_b_btm(t_data, int pos)
{
	if (pos % 3 == 1)
		;
	else if (pos % 3 == 2)
		;
	else
		;
}

void	collect(t_data data, int pos)
{
	if (pos % 3 == 1)
		;
	else if (pos % 3 == 2)
		;
	else
		;
}

t_pair	partitioning(t_data data, size_t low, size_t high, int *pos)
{
	t_pair	part_i;
	t_pair	pivot_v;
	t_node	*start_node;

	part_i.former = low;
	part_i.latter = high;
	start_node = get_start_node(data, pos);
	pivot_v = find_pivot(start_node, low, high, pos);
	while (high > low++)
	{
		if (start_node->content < pivot_v.former)
		{
			part_i.former++;
			move_to_a_top(data, pos); //biggers
		}
		else if (start_node->content >= pivot_v.former && start_node->content <= pivot_v.latter)
			move_to_b_top(data, pos); //medians
		else
		{
			part_i.latter++;
			move_to_b_btm(data, pos); //smallers
		}
		collect(data, pos);
	}
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
