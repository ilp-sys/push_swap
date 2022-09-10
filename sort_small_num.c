/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:03:47 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/10 15:55:20 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_1(t_data data, int pos)
{
	if (pos != A_TOP)
		move_to_a_top(data, pos);
}

void	sort_2(t_data data, int pos)
{
	t_node	*a_top;

	if (pos != A_BTM && pos != A_TOP)
		move_to_iter(data, 2, pos, &move_to_a_top);
	a_top = get_last_node(data.stack[0]);
	if (a_top->content > a_top->prev->content)
	{
		operation_swap(data.stack[0]);
		append_to_ops(data.ops, sa);
	}
}

void	sort_3(t_data data, int pos)
{
	int		i;
	int		cnt;
	int		sorted;
	int		median;
	t_node	*start_node;

	i = 0;
	cnt = 0;
	start_node = get_start_node(data, pos);
	if (is_sorted_sort_3(data, pos) == -1)
		return ;
	median = find_pivot(start_node, 3, pos).former;
	while (i++ < 3)
	{
		if (start_node->content >= median)
			cnt += move_to_a_top(data, pos);
		else
			cnt += move_to_b_top(data, pos);
		start_node = get_start_node(data, pos);
	}
	if (cnt)
		collect(data, pos, cnt);
	sort_2(data, A_TOP);
	operation_push(data.stack[1], data.stack[0]);
	append_to_ops(data.ops, pa);
}

void	sort_4(t_data data, int pos)
{
	int		i;
	int		cnt;
	t_node	*start_node;
	t_pair	pivot_v;

	if (is_sorted_sort_4(data, pos) == -1)
		return ;
	i = 0;
	cnt = 0;
	start_node = get_start_node(data, pos);
	pivot_v = find_pivot(start_node, 4, pos);
	while (i++ < 4)
	{
		if (start_node->content > pivot_v.former)
			cnt += move_to_a_top(data, pos);
		else
			cnt += move_to_b_top(data, pos);
		start_node = get_start_node(data, pos);
	}
	if (cnt)
		collect(data, pos, cnt);
	sort_2(data, A_TOP);
	move_to_iter(data, 2, B_TOP, &move_to_a_top);
	sort_2(data, A_TOP);
}
