/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:19:59 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/10 17:24:18 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	move_to_iter(t_data data, int iter, int pos, \
		size_t (*f)(t_data data, int pos))
{
	size_t	cnt;

	cnt = 0;
	while (iter--)
		cnt += f(data, pos);
	return (cnt);
}

size_t	move_to_a_top(t_data data, int pos)
{
	size_t	cnt;

	cnt = 0;
	if (pos == A_BTM)
	{
		if (get_queue_size(data.stack[0]) != 1)
			execute_append(data, rra);
	}
	else if (pos == A_TOP)
	{
		if (get_queue_size(data.stack[0]) != 1)
		{
			execute_append(data, ra);
			cnt++;
		}
	}
	else if (pos == B_TOP)
		execute_append(data, pa);
	else
	{
		if (get_queue_size(data.stack[1]) != 1)
			execute_append(data, rrb);
		execute_append(data, pa);
	}
	return (cnt);
}

size_t	move_to_b_top(t_data data, int pos)
{
	size_t	cnt;

	cnt = 0;
	if (pos == A_BTM)
	{
		execute_append(data, rra);
		execute_append(data, pb);
	}
	else if (pos == A_TOP)
		execute_append(data, pb);
	else if (pos == B_TOP)
	{
		execute_append(data, pa);
		execute_append(data, ra);
		cnt++;
	}
	else
		execute_append(data, rrb);
	return (cnt);
}

size_t	move_to_b_btm(t_data data, int pos)
{
	size_t	cnt;

	cnt = 0;
	if (pos == A_BTM)
	{
		if (get_queue_size(data.stack[0]) != 1)
			execute_append(data, rra);
		execute_append(data, pb);
		if (get_queue_size(data.stack[1]) != 1)
			execute_append(data, rb);
	}
	else if (pos == A_TOP)
	{
		execute_append(data, pb);
		execute_append(data, rb);
	}
	else if (pos == B_TOP)
		execute_append(data, rb);
	else
	{
		execute_append(data, rrb);
		execute_append(data, pa);
		execute_append(data, ra);
		cnt++;
	}
	return (cnt);
}
