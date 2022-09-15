/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:55:19 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/16 01:00:35 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_ops_frame(t_deq ops)
{
	if (ops.head)
	{
		while (ops.head->next)
			ops.head = ops.head->next;
		while (ops.head)
		{
			print_ops(ops.head);
			ops.head = ops.head->prev;
		}
	}
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


int	main(int argc, char *argv[])
{
	t_deq	*stack_a;
	t_deq	*stack_b;
	t_deq	*ops;

	queue_init(&stack_a);
	queue_init(&stack_b);
	queue_init(&ops);
	if (argc > 1)
	{
		get_input(argc, argv, stack_a);
		push_swap(stack_a, stack_b, ops);
		print_ops_frame(*ops);
	}
	return (0);
}
