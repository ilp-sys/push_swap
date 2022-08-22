/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:30:48 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/22 10:45:45 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_err_exit()
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_ops(t_node *ops)
{
	if (ops->content == 0)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (ops->content == 1)
		write(STDOUT_FILENO, "sb\n", 3);
	else if (ops->content == 2)
		write(STDOUT_FILENO, "ss\n", 3);
	else if (ops->content == 3)
		write(STDOUT_FILENO, "pa\n", 3);
	else if (ops->content == 4)
		write(STDOUT_FILENO, "pb\n", 3);
	else if (ops->content == 5)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (ops->content == 6)
		write(STDOUT_FILENO, "rb\n", 3);
	else if (ops->content == 7)
		write(STDOUT_FILENO, "rr\n", 3);
	else if (ops->content == 8)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (ops->content == 9)
		write(STDOUT_FILENO, "rrb\n", 4);
	else if (ops->content == 10)
		write(STDOUT_FILENO, "rrr\n", 4);
	head = head->next;
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
