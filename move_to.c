/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:19:59 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/07 20:39:15 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	move_to_a_top(t_data data, int pos)
{
	size_t	cnt;

	cnt = 0;
	if (pos == A_BTM)
	{
		if (get_queue_size(data.stack[0]) != 1)
		{
			operation_reverse_rotate(data.stack[0]);
			append_to_ops(data.ops, rra);
		}
	}
	else if (pos == A_TOP)
	{
		if (get_queue_size(data.stack[0]) != 1)
		{
			operation_rotate(data.stack[0]);
			append_to_ops(data.ops, ra);
			cnt++;
		}
	}
	else if (pos == B_TOP)
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
	return (cnt);
}

size_t	move_to_b_top(t_data data, int pos)
{
	size_t	cnt;

	cnt = 0;
	if (pos == A_BTM)
	{
		operation_reverse_rotate(data.stack[0]);
		append_to_ops(data.ops, rra);
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
	}
	else if (pos == A_TOP)
	{
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
	}
	else if (pos == B_TOP) //move to A btm tentatively
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
	if (pos == A_BTM)
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
	else if (pos== A_TOP)
	{
		operation_push(data.stack[0], data.stack[1]);
		append_to_ops(data.ops, pb);
		operation_rotate(data.stack[1]);
		append_to_ops(data.ops, rb);
	}
	else if (pos == B_TOP)
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

