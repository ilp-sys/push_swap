/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:30:48 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/29 21:19:35 by jiwahn           ###   ########.fr       */
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
	head = head->next;
}

void	init_data(t_deq *stack_a, t_deq *stack_b, t_deq *ops, t_data *data)
{
	data.stack[0] = stack_a;
	data.stack[1] = stack_a;
	data.ops = ops;
}

t_pair	find_pivot(t_data data, size_t low, size_t high, int pos)
{
	int		i;
	t_pair	pivot_v;
	size_t	size;
	t_node	*start_node;
	int		tmp[high - low];

	i = 0;
	size = high - low;
	ft_memset(tmp, 0, size);
	while (i < size)
	{

		i++;
	}
	pivot_v.former = 
	return (pivot_v);
}

t_node	*get_start_node(t_node *data, int pos)
{
	t_node	*start_node;

	if (pos % 3 == 0)
		start_node = get_last_node(data.queue[0]);
	else if (pos % 3 == 1)
		start_node = get_last_node(data.queue[1]);
	else
		start_node = data.queue[1]->head;
	return (start_node);
}
