/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:50:17 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 18:51:03 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_next_node(t_node *node, int pos)
{
	if (pos == 0 || pos == 3)
		return (node->next);
	else
		return (node->prev);
}

t_node	*get_start_node(t_data data, int pos)
{
	t_node	*start_node;

	if (pos == 0)
		start_node = data.stack[0]->head;
	else if (pos == 1)
		start_node = get_last_node(data.stack[0]);
	else if (pos == 2)
		start_node = get_last_node(data.stack[1]);
	else
		start_node = data.stack[1]->head;
	return (start_node);
}

void	parse_err_exit(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	print_ops(t_node *ops)
{
	if (ops->content == sa)
		write(STDOUT_FILENO, "sa\n", 3);
	else if (ops->content == sb)
		write(STDOUT_FILENO, "sb\n", 3);
	else if (ops->content == ss)
		write(STDOUT_FILENO, "ss\n", 3);
	else if (ops->content == pa)
		write(STDOUT_FILENO, "pa\n", 3);
	else if (ops->content == pb)
		write(STDOUT_FILENO, "pb\n", 3);
	else if (ops->content == ra)
		write(STDOUT_FILENO, "ra\n", 3);
	else if (ops->content == rb)
		write(STDOUT_FILENO, "rb\n", 3);
	else if (ops->content == rr)
		write(STDOUT_FILENO, "rr\n", 3);
	else if (ops->content == rra)
		write(STDOUT_FILENO, "rra\n", 4);
	else if (ops->content == rrb)
		write(STDOUT_FILENO, "rrb\n", 4);
	else if (ops->content == rrr)
		write(STDOUT_FILENO, "rrr\n", 4);
}

t_data	init_data(t_deq *stack_a, t_deq *stack_b, t_deq *ops)
{
	t_data	data;

	data.stack[0] = stack_a;
	data.stack[1] = stack_b;
	data.ops = ops;
	return (data);
}