/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:55:19 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/30 19:10:34 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

/*
#include <stdio.h>
void	print_queue(t_deq *deq)
{
	t_node 	*tmp;

	printf("[STACK_A(%d)] ", deq->size);
	tmp = deq->head;
	while (tmp)
	{
		printf("%d - ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}
*/

void	sort_small_num(t_data data, size_t high, size_t low, int pos)
{
	//move required num of nodes to other top
	//sort
}

int main(int argc, char *argv[])
{
	t_deq	*stack_a;
	t_deq	*stack_b;
	t_deq	*ops;

	queue_init(&stack_a);
	queue_init(&stack_b);
	queue_init(&ops);
	if (argc > 2)
	{
		get_input(argc, argv, stack_a); 	//parse
		push_swap(stack_a, stack_b, ops); 	//sort
		while (ops->head->next) 			//print
			ops->head = ops->head->next;	//push front when you append
		while (ops->head)
		{
			print_ops(ops->head);
			ops->head = ops->head->prev;
		}
	}
//	print_queue(stack_a); 
//	print_queue(stack_b); 
	return (0);
}
