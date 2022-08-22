/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/22 17:56:15 by jiwahn           ###   ########.fr       */
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

void	build_right_bottom(t_deq *queue_a, t_deq *queue_b)
{
	int		iter_count;
	size_t	sorted[3];
	t_deq	*queue_c;
	size_t	size;
	t_info	infos[3];

	iter_count = 1;
	queue_init(queue_c);
	size = get_queue_size(queue_a) / 3; 
	while (size -= sum_sorted(sorted) > 0)
	{
		if (iter_count % 2)
			//do something
			;
		else
			;

		iter_count++;
	}
	//move to queue_c from queue_b
	free_queue(&quque_c);
}

void	build_right_top(t_deq *queue_a, t_deq *queue_b)
{

}

void	build_left_bottom(t_deq *queue_a, t_deq *queue_b)
{
}

void	merge_all(t_deq *queue_a, t_deq *queue_b, t_deq *ops)
{
	t_node	*end1;
	t_node	*end2;
	t_node	*end3;

	end1 = queue_a->head;
	end2 = queue_b->head;
	end3 = get_last_node(queue_b);

}

void	push_swap(t_deq *queue_a, t_deq *queue_b, t_deq *ops)
{
	build_right_bottom(queue_a, queue_b);
	build_right_top(queueu_a, queue_b);
	build_left_bottom(queue_a, queue_b);
	merge_all(queue_a, queue_b, ops);
}
