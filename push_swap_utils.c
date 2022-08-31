/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:30:48 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/31 21:16:42 by jiwahn           ###   ########.fr       */
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
}

t_data	init_data(t_deq *stack_a, t_deq *stack_b, t_deq *ops)
{
	t_data	data;

	data.stack[0] = stack_a;
	data.stack[1] = stack_b;
	data.ops = ops;
	return (data);
}

t_pair	find_pivot(t_node *start_node, size_t low, size_t high, int pos)
{
	t_pair	idx;
	t_pair	min;
	t_pair	pivot_v;
	t_node	*cur_node;
	int		tmp[high - low]; //TODO - possible risk

	idx.former = 0;
	idx.latter = 0;
	min.former = INT_MIN; //abs min
	min.latter = start_node->content; //cur min
	cur_node = start_node;
	ft_memset(tmp, 0, high - low);
	while (idx.former < high - low)
	{
		cur_node = start_node;
		while (idx.latter < high - low)
		{
			if (cur_node->content >= min.former && cur_node->content < min.latter)
				min.latter = cur_node->content;
			cur_node = get_next_node(cur_node, pos);
			idx.latter++;
		}
		tmp[idx.former++] = min.latter;
		min.former = min.latter;
	}
	pivot_v.former = tmp[(high - low) / 3 * 1];
	pivot_v.latter = tmp[(high - low) / 3 * 2];
	return (pivot_v);
}

t_node	*get_start_node(t_data data, int pos)
{
	t_node	*start_node;

	if (pos % 3 == 0)
		start_node = get_last_node(data.stack[0]);
	else if (pos % 3 == 1)
		start_node = get_last_node(data.stack[1]);
	else
		start_node = data.stack[1]->head;
	return (start_node);
}

t_node	*get_next_node(t_node *node, int pos)
{
	if (pos % 3 == 2)
		return (node->next);
	else 
		return (node->prev);
}
