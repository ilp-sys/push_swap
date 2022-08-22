/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/22 13:30:28 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	sorted_ascend(t_deq *queue, int top)
{
	t_node	*head;
	t_node	*next;
	size_t	sorted;

	sorted = 1;
	head = queue->head;
	if (top)
		while (head->next)
			head = head->next;
	while (1)
	{
		if (top)
			next = head->prev;
		else 
			next = head->next;
		if (next == NULL)
			break ;
		if (head->content < next->content)
			sorted++;
		else
			break ;
	}
	return (sorted);
}

size_t sorted_descend(t_deq *queue, int top)
{
	t_node	*head;
	t_node	*next;
	size_t	sorted;

	sorted = 1;
	head = queue->head;
	if (top)
		while (head->next)
			head = head->next;
	while (1)
	{
		if (top)
			next = head->prev;
		else 
			next = head->next;
		if (next == NULL)
			break ;
		if (head->content > next->content)
			sorted++;
		else
			break ;
	}
	return (sorted);
}

void	build_right_bottom(t_deq *queue_a, t_deq *queue_b, t_deq *ops, int *pos)
{
	size_t			count;
	size_t			sorted[3];
	const size_t	size = get_queue_size(queue_a);

	count = 0;
	while (count < size / 3)
	{

	}
}

void	build_right_top(t_deq *queue_a, t_deq *queue_b, t_deq *ops, int *pos)
{

}

void	build_left_bottom(t_deq *queue_a, t_deq *queue_b, t_deq *ops, int *pos)
{

}

void	push_swap(t_deq *queue_a, t_deq *queue_b, t_deq *ops)
{
	int		pos;

	pos = 1;
	build_right_bottom(queue_a, queue_b, ops, &pos);
	build_right_top(queueu_a, queue_b, ops, &pos);
	build_left_bottom(queue_a, queue_b, ops, &pos);
	merge(queue_a, queue_b, ops, &pos);
}
