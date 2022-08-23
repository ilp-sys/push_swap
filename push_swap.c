/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/23 17:26:04 by jiwahn           ###   ########.fr       */
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

t_info	set_info(t_deq *queue_a, t_deq *queue_b, int iter_count)
{
	t_info	info[3];

	if (iter_count % 2)
	{
		info[0].from = queue_a->head;
		info[1].from = get_last_node(queue_a);
		info[2].from = queue_b->head;
		info[0].till = sorted_ascend(info[0].from, 0);
		info[1].till = sorted_ascend(info[1].from, 1);
		info[2].till = sorted_ascend(info[2].from, 0);
	}
	else
	{
		info[0].from = queue_a->head;
		info[1].from = get_last_node(queue_a);
		info[2].from = queue_b->head;
		info[0].till = sorted_descend(info[0].from, 0);
		info[1].till = sorted_descend(info[1].from, 1);
		info[2].till = sorted_descend(info[2].from, 0);
	}
	return (info);
}

int find_min(t_info info[3])
{
	long long	num0;
	long long	num1;
	long long	num2;

	if (info[0].from)
		num0 = info[0]->content;
	else
		num0 = INT_MAX + 1;
	if (info[1].from)
		num1 = info[1]->content;
	else
		num1 = INT_MAX + 1;
	if (info[2].from)
		num2 = info[2]->content;
	else
		num2 = INT_MAX + 1;
	if (num0 <= num1 && num0 <= num2)
		return (0);
	if (num1 <= num0 && num1 <= num2)
		return (1);
	else
		return (2);
}
}

void	merge(t_info info[3], t_deq *queue_a, t_deq *queue_b, int iter_count)
{
	int	min;

	while (info[0].till == 0 && info[1].till == 0 && info[2].till == 0)
	{
		min = find_min(info);
		if (min == 0)
			info[0].till--;
		else if (min == 1)
			info[1].till--;
		else
			info[2].till--;
	}
}

void	build_right_bottom(t_deq *queue_a, t_deq *queue_b)
{
	int		iter_count;
	size_t	size;
	size_t	sum;
	t_info	info[3];

	sum = 0;
	iter_count = 1;
	size = get_queue_size(queue_a) / 3; 
	while (1)
	{
		info  = set_info(queue_a, qubue_b, iter_count);
		merge(info, queue_a, queue_b, iter_count);
		iter_count++;
		sum += sum_sorted(info);
		if (size < sum)
			break ;
	}
}

void	build_right_top(t_deq *queue_a, t_deq *queue_b)
{

}

void	build_left_bottom(t_deq *queue_a, t_deq *queue_b)
{
}

void	push_swap(t_deq *queue_a, t_deq *queue_b, t_deq *ops)
{
	build_right_bottom(queue_a, queue_b);
	build_right_top(queueu_a, queue_b);
	build_left_bottom(queue_a, queue_b);
	merge();
}
