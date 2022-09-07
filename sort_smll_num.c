/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smll_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:03:47 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/07 20:05:12 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small_num(t_data data, size_t high, size_t low, int pos)
{
	if (high - low == 0)
		return ;
	else if (high - low == 1)
		sort_1(data, pos);
	else if (high - low == 2)
		sort_2(data, pos);
	else if (high - low == 3)
		sort_3(data, pos);
	else
		sort_4(data, pos);
}

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

void	sort_3(t_data data, int pos) //single pivot quick sort
{
	int	cnt;
	int	sorted;
	int median;
	t_node	*start_node;

	cnt = 0;
	start_node = get_start_node(data, pos);
	sorted = is_sorted_sort_3(data, pos);
	if (sorted == -1)
		return ;
	else
		median = sorted;

	for (int i = 0; i < 3; i++)
	{
		if (start_node->content >= median)
			cnt += move_to_a_top(data, pos);
		else
			cnt += move_to_b_top(data, pos);
		start_node = get_start_node(data, pos);
	}
	if (cnt)
		collect(data, pos, cnt); //collect in case of pos equals 1
	sort_2(data, 1);
	operation_push(data.stack[1], data.stack[0]);
	append_to_ops(data.ops, pa);
}

void	sort_4(t_data data, int pos) //single pivot quick sort
{
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
	start_node = get_start_node(data, pos);
	pivot_v = find_pivot(start_node, 0, 4, pos);
	for (int i = 0; i < 4; i++)
	{
		if (start_node->content > pivot_v.former)
		{
			if (pos != A_BTM)
			{
				move_to_a_top(data, pos);
			}
		}
		else
			move_to_b_top(data, pos);
		start_node = get_start_node(data, pos);
	}
	sort_2(data, A_TOP);
	for (int i = 0; i < 2; i++)
		move_to_a_top(data, 2);
	sort_2(data, A_TOP);
}

int	check_type(t_node *start_node)
{
	const int	num1 = start_node->content;
	const int	num2 = start_node->prev->content;
	const int	num3 = start_node->prev->prev->content;

	if (num1 < num2 && num1 < num3)
	{
		if (num2 < num3)
			return (0);
		else
			return (1);
	}
	else if (num2 < num1 && num2 < num3)
	{
		if (num1 < num3)
			return (1);
		else
			return (2);
	}
	else
	{
		if (num1 < num2)
			return (3);
		else
			return (1);
	}
}

