/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:21:33 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/24 23:21:55 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_swap(t_deq *queue)
{
	t_node	*popped1; 
	t_node	*popped2; 

	popped1 = queue_pop_back(queue);
	popped2 = queue_pop_back(queue);
	if (popped1)
		popped1->prev = NULL;
	queue_push_back(queue, popped1);
	queue_push_back(queue, popped2);
}

void	operation_push(t_deq *src, t_deq *dst)
{
	t_node	*popped;

	popped = queue_pop_back(src);
	if (popped)
		popped->prev = NULL;
	queue_push_back(dst, popped);
}

void	operation_rotate(t_deq *queue) //shift up
{
	t_node	*popped;

	popped = queue_pop_back(queue);
	if (popped)
		popped->prev = NULL;
	queue_push_front(queue, popped);
}

void	operation_reverse_rotate(t_deq *queue) //shift down
{
	t_node	*popped;

	popped = queue_pop_front(queue);
	if (popped)
		popped->next = NULL;
	queue_push_back(queue, popped);
}

//not needed I guess
//void	operate(t_deq *ops, int op, t_data data)
//{
//	if (op == sa)
//		operate_swap(data.queue_a);
//	else if (op == sb)
//		operate_swap(data.queue_b);
//	else if (op == pa)
//		operate_push(data.queue_b, data.queue_a);
//	else if (op == pb)
//		operate_push(data.queue_a, data.queue_b);
//	else if (op == ra)
//		operate_rotate(data.queue_a);
//	else if (op == rb)
//		operate_rotate(data.queue_b);
//	else if (op == rr)
//		operate_rotate(data.queue_a);
//	else if (op == rra)
//		operate_reverse_rotate(data.queue_a);
//	else if (op == rrb)
//		operate_reverse_rotate(data.queue_a);
//	else if (op == rrr)
//		operate_reverse_rotate(data.queue_a);
//	append_to_ops(ops, op);
//}
