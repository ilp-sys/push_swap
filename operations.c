/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:21:33 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 18:46:25 by jiwahn           ###   ########.fr       */
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

void	operation_rotate(t_deq *queue)
{
	t_node	*popped;

	popped = queue_pop_back(queue);
	if (popped)
		popped->prev = NULL;
	queue_push_front(queue, popped);
}

void	operation_reverse_rotate(t_deq *queue)
{
	t_node	*popped;

	popped = queue_pop_front(queue);
	if (popped)
		popped->next = NULL;
	queue_push_back(queue, popped);
}
