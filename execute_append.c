/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_append.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 16:43:49 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/17 22:44:34 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_swap(t_data data, int op)
{
	if (op == sa)
		operation_swap(data.stack[0]);
	else if (op == sb)
		operation_swap(data.stack[1]);
	else
	{
		operation_swap(data.stack[0]);
		operation_swap(data.stack[1]);
	}
	append_to_ops(data, op);
}

static void	run_push(t_data data, int op)
{
	if (op == pa)
		operation_push(data.stack[1], data.stack[0]);
	else
		operation_push(data.stack[0], data.stack[1]);
	append_to_ops(data, op);
}

static void	run_rotate(t_data data, int op)
{
	if (op == ra)
		operation_rotate(data.stack[0]);
	else if (op == rb)
		operation_rotate(data.stack[1]);
	else
	{
		operation_rotate(data.stack[0]);
		operation_rotate(data.stack[1]);
	}
	append_to_ops(data, op);
}

static void	run_reverse_rotate(t_data data, int op)
{
	if (op == rra)
		operation_reverse_rotate(data.stack[0]);
	else if (op == rrb)
		operation_reverse_rotate(data.stack[1]);
	else
	{
		operation_reverse_rotate(data.stack[0]);
		operation_reverse_rotate(data.stack[1]);
	}
	append_to_ops(data, op);
}

void	execute_append(t_data data, int op)
{
	if (op == sa || op == sb || op == ss)
		run_swap(data, op);
	else if (op == pa || op == pb)
		run_push(data, op);
	else if (op == ra || op == rb || op == rr)
		run_rotate(data, op);
	else
		run_reverse_rotate(data, op);
}
