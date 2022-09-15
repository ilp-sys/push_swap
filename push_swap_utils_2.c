/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:50:17 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/16 01:00:33 by jiwahn           ###   ########.fr       */
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

t_data	init_data(t_deq *stack_a, t_deq *stack_b, t_deq *ops)
{
	t_data	data;

	data.stack[0] = stack_a;
	data.stack[1] = stack_b;
	data.ops = ops;
	return (data);
}
