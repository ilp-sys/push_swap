/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:38:28 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 18:36:55 by jiwahn           ###   ########.fr       */
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
		queue_pop_front(ops);
	else
		queue_push_front(ops, get_new_node(op));
}

void	optimize_push(t_deq *ops, int op)
{
	int	num;

	num = ops->head->content + op;
	if (num == pa + pb)
		queue_pop_front(ops);
	else
		queue_push_front(ops, get_new_node(op));
}

void	optimize_rotate(t_deq *ops, int op)
{
	int	num;

	num = ops->head->content + op;
	if ((ops->head->content == rra && op == rrb) || \
			(ops->head->content == rrb && op == rra))
		ops->head->content = rrr;
	else if (num == ra + rb)
		ops->head->content = rr;
	else
		queue_push_front(ops, get_new_node(op));
}

void	append_to_ops(t_deq *ops, int op)
{
	int	prev_op;

	prev_op = 0;
	if (ops->head)
	{
		prev_op = ops->head->content;
		if ((op == sa || op == sb || op == ss) && \
				(prev_op == sa || prev_op == sb || prev_op == ss))
			optimize_swap(ops, op);
		else if ((op == pa || op == pb) && \
				(prev_op == pa || prev_op == pb))
			optimize_push(ops, op);
		else if ((op == ra || op == rb || op == rr || \
				op == rra || op == rrb || op == rrr) && \
				(prev_op == ra || prev_op == rb || prev_op == rr || \
				prev_op == rra || prev_op == rrb || prev_op == rrr))
			optimize_rotate(ops, op);
		else
			queue_push_front(ops, get_new_node(op));
	}
	else
		queue_push_front(ops, get_new_node(op));
}
