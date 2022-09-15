/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:55:19 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/16 00:46:45 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_deq	*stack_a;
	t_deq	*stack_b;
	t_deq	*ops;
	t_node	*tmp;

	queue_init(&stack_a);
	queue_init(&stack_b);
	queue_init(&ops);
	if (argc > 1)
	{
		get_input(argc, argv, stack_a);
		push_swap(stack_a, stack_b, ops);
		if (ops->head)
		{
			while (ops->head->next)
				ops->head = ops->head->next;
			while (ops->head)
			{
				print_ops(ops->head);
				tmp = ops->head;
				ops->head = ops->head->prev;
				free(tmp);
			}
		}
	}
}
