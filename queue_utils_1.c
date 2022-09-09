/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:35:32 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 18:35:57 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*queue_pop_back(t_deq *queue)
{
	t_node	*popped;

	if (queue->size < 1)
		return (NULL);
	else if (queue->size == 1)
	{
		popped = queue->head;
		queue->head = NULL;
	}
	else
	{
		popped = queue->head;
		while (popped->next)
			popped = popped->next;
		popped->prev->next = NULL;
	}
	(queue->size)--;
	return (popped);
}

t_node	*queue_pop_front(t_deq *queue)
{
	t_node	*popped;

	popped = queue->head;
	if (queue->size > 0)
	{
		if (popped)
			queue->head = popped->next;
		if (queue->head)
			queue->head->prev = NULL;
		(queue->size)--;
	}
	return (popped);
}

void	queue_push_back(t_deq *queue, t_node *node)
{
	t_node	*tmp;

	if (queue == NULL || node == NULL)
		return ;
	if (queue->size < 1)
		queue->head = node;
	else
	{
		tmp = queue->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
	(queue->size)++;
}

void	queue_push_front(t_deq *queue, t_node *node)
{
	t_node	*tmp;

	if (queue == NULL || node == NULL)
		return ;
	tmp = queue->head;
	if (tmp == NULL)
		queue->head = node;
	else
	{
		queue->head = node;
		node->next = tmp;
		tmp->prev = node;
	}
	(queue->size)++;
}
