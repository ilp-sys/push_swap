/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:30:48 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/03 14:33:21 by jiwahn           ###   ########.fr       */
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
	int		min;
	int		min_idx;
	t_pair	pivot_v;
	t_pair	idx;
	t_node	*cur_node;
	int		dsc_ord[high - low];
	int		marked[high - low];

	idx.former = 0;
	ft_memset(marked, 0, high - low);
	while (idx.former < (int)(high - low))
	{
		min = INT_MAX;
		min_idx = -1;
		idx.latter = 0;
		cur_node = start_node;
		while (idx.latter < (int)(high - low))
		{
			if (marked[idx.latter] == 1)
				;
			else if (cur_node->content <= min)
			{
				min = cur_node->content;
				min_idx = idx.latter;
			}
			cur_node = get_next_node(cur_node, pos);
			idx.latter++;
		}
		marked[min_idx] = 1;
		dsc_ord[idx.former++] = min;
	}
	pivot_v.former = dsc_ord[(high - low) / 3 * 1 - 1];
	pivot_v.latter = dsc_ord[(high - low) / 3 * 2 - 1];
	return (pivot_v);
}

t_node	*get_start_node(t_data data, int pos)
{
	t_node	*start_node;

	if (pos % 3 == 0)
		start_node = data.stack[1]->head;
	else if (pos % 3 == 1)
		start_node = data.stack[0]->head;
	else
		start_node = get_last_node(data.stack[1]);
	return (start_node);
}

t_node	*get_next_node(t_node *node, int pos)
{
	if (pos % 3 == 2)
		return (node->prev);
	else
		return (node->next);
}
