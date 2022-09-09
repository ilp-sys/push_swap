/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:34:26 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 18:36:36 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_new_node(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->content = content;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_node	*get_last_node(t_deq *queue)
{
	t_node	*last;

	last = queue->head;
	while (last->next)
		last = last->next;
	return (last);
}

size_t	get_queue_size(t_deq *queue)
{
	size_t	size;
	t_node	*head;

	size = 0;
	head = queue->head;
	while (head)
	{
		size++;
		head = head->next;
	}
	return (size);
}

void	queue_init(t_deq **queue)
{
	*queue = (t_deq *)malloc(sizeof(t_deq));
	(*queue)->size = 0;
	(*queue)->head = NULL;
}
