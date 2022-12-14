/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:38:28 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/18 00:35:30 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	optimize_swap(t_deq *ops, int op)
{
	int	num;

	num = ops->head->content + op;
	if (num == sa + sb)
		ops->head->content = ss;
	else if (num == sa + sa || num == sb + sb)
		free(queue_pop_front(ops));
	else
		queue_push_front(ops, get_new_node(op));
}

void	optimize_push(t_deq *ops, int op)
{
	int	num;

	num = ops->head->content + op;
	if (num == pa + pb)
		free(queue_pop_front(ops));
	else
		queue_push_front(ops, get_new_node(op));
}

void	optimize_rotate(t_deq *ops, int op)
{
	if ((ops->head->content == rra && op == rrb) || \
			(ops->head->content == rrb && op == rra))
		ops->head->content = rrr;
	else if ((ops->head->content == ra && op == rb) || \
			(ops->head->content == rb && op == ra))
		ops->head->content = rr;
	else if ((ops->head->content == rr && op == rrr) || \
			(ops->head->content == rrr && op == rr) || \
			(ops->head->content == ra && op == rra) || \
			(ops->head->content == rra && op == ra) || \
			(ops->head->content == rb && op == rrb) || \
			(ops->head->content == rrb && op == rb))
		free(queue_pop_front(ops));
	else
		queue_push_front(ops, get_new_node(op));
}

static int	catch_exception(t_data data, int prev_op, int op)
{
	if (data.stack[0]->size == 2 && \
			((prev_op == rra && op == sa) || \
			(prev_op == ra && op == sa) || \
			(prev_op == sa && op == rra) || \
			(prev_op == sa && op == ra)))
	{
		free(queue_pop_front(data.ops));
		return (1);
	}
	return (0);
}

void	append_to_ops(t_data data, int op)
{
	int		prev_op;
	t_deq	*ops;

	ops = data.ops;
	if (!ops->head)
	{
		queue_push_front(ops, get_new_node(op));
		return ;
	}
	prev_op = ops->head->content;
	if (catch_exception(data, prev_op, op))
		return ;
	if ((op == sa || op == sb || op == ss) && \
			(prev_op == sa || prev_op == sb || prev_op == ss))
		optimize_swap(ops, op);
	else if ((op == pa || op == pb) && \
			(prev_op == pa || prev_op == pb))
		optimize_push(ops, op);
	else if ((op == ra || op == rb || op == rr || \
			op == rra || op == rrb || op == rrr) || \
			(prev_op == ra || prev_op == rb || prev_op == rr || \
			prev_op == rra || prev_op == rrb || prev_op == rrr))
		optimize_rotate(ops, op);
	else
		queue_push_front(ops, get_new_node(op));
}
