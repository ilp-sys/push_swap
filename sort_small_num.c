/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:03:47 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 21:16:17 by jiwahn           ###   ########.fr       */
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
	int		i;
	t_node	*a_top;

	i = 0;
	if (pos != A_BTM && pos != A_TOP)
		while (i++ < 2)
			move_to_a_top(data, pos);
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
	sorted = is_sorted_sort_3(data, pos);
	if (sorted == -1)
		return ;
	else
		median = find_pivot(start_node, 0, 3, pos).former;
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
	int		cnt;
	t_node	*start_node;
	t_pair	pivot_v;

	if (is_sorted_sort_4(data, pos) == -1)
	{
		if (pos == B_TOP || pos == B_BTM)
		{
			for(int i = 0; i < 4; i++)
				move_to_a_top(data, pos);
		}
		return ;
	}
	cnt = 0;
	start_node = get_start_node(data, pos);
	pivot_v = find_pivot(start_node, 0, 4, pos);
	for (int i = 0; i < 4; i++)
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
	for (int i = 0; i < 2; i++)
		move_to_a_top(data, B_TOP);
	sort_2(data, A_TOP);
}
