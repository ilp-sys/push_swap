/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adding_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 20:38:28 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/24 22:22:20 by jiwahn           ###   ########.fr       */
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
	if ((ops->head->content == rra && op == rrb) ||\
			(ops->head->content == rrb && op == rra))
		ops->head->content = rrr;
	else if (num == ra + rb)
		ops->head->content = rr;
	else if (num == ra + rra ||\
			num == rb + rrb ||\
			num == rr + rrr)
		queue_pop_front(ops);
	else
		queue_push_front(ops, get_new_node(op));
}

void	append_to_ops(t_deq *ops, int op)
{
	if (ops->head == NULL)
	{
		queue_push_front(ops, get_new_node(op));
		return ;
	}
	if (op == sa || op == sb || op == ss)
		optimize_swap(ops, op);
	else if (op == pa || op == pb)
		optimize_push(ops, op);
	else if (op == ra || op == rb || op == rr ||\
			 op == rra || op == rrb || op == rrr)
		optimize_rotate(ops, op);
}
