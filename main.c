/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:55:19 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/31 21:21:48 by jiwahn           ###   ########.fr       */
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

void	sort_1(t_data data, int pos)
{
	if (pos % 3 != 1)
		move_to_a_top(data, pos);
}

void	sort_2(t_data data, int pos)
{
	const t_node	*curr_node = get_start_node(data, pos);
	const t_node	*next_node = get_next_node(data, pos);

	if (pos % 3 == 1)
	{
		if (curr_node->content > next_node->content)
		{
			operation_swap(data.stack[0]);
			append_to_ops(data.ops, sa);
		}
	}
	else
	{
		if (pos % 3 == 0)
		{
			operation_reverse_rotate(data.stack[1]);
			append_to_ops(data.ops, rrb);
			operation_reverse_rotate(data.stack[1]);
			append_to_ops(data.ops, rrb);
		}
		if (curr_node->content < next_node->content && (pos % 3) == 2)
		{
			operation_swap(data.stack[1]);
			append_to_ops(data.ops, sb);
		}
		else if (curr_node->content > next_node->content && (pos % 3) == 0)
		{
			operation_swap(data.stack[1]);
			append_to_ops(data.ops, sb);
		}
		operation_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
		operation_push(data.stack[1], data.stack[0]);
		append_to_ops(data.ops, pa);
	}
}

int	check_type(t_node *start_node)
{
	const int num1 = start_node->content;
	const int num2 = start_node->prev->content;
	const int num3 = start_node->prev->prev->content;

	if (num1 < num2 && num1 < num2)
	{
		if (num2 < num3)
			return (0);
		else
			return (1);
	}
	else if (num2 < num3 && num2 < num1)
	{
		if (num1 < num3)
			return (1);
		else
			return (2);
	}
	else if (num3 < num1 && num3 < num1)
	{
		if (num1 > num2)
			return (1);
		else 
			return (3);
	}
}

void	sort_3(t_data data, int pos)
{
	int	i;
	int	type;

	i = 0;
	if (pos % 3 == 0)
		while (i++ < 3)
		{
			operation_reverse_rotate(data.stack[1]);
			append_to_ops(data.ops, rrb);
		}
	i = 0;
	if (pos % 3 == 0 || pos % 3 == 2)
		while (i++ < 3)
		{
			operation_push(data.stack[1], data.stack[0]);
			append_to_ops(data.ops, pa);
		}
	while (1)
	{
		type = check_type(data.stack[0]->head);
		if (type == 0)
			break ;
		else if (type == 1)
		{
			operation_swap(data.stack[0]);
			append_to_ops(data.ops, sa);
		}
		else if (type == 2)
		{
			operation_rotate(data.stack[0]);
			append_to_ops(data.ops, ra);
		}
		else if (type == 3)
		{
			operation_reverse_rotate(data.stack[0]);
			append_to_ops(data.ops, rra);
		}
	}
}

void	sort_small_num(t_data data, size_t high, size_t low, int pos)
{
	if (high - low == 0)
		return ;
	else if (high - low == 1)
		sort_1(data, pos);
	else if (high - low == 2)
		sort_2(data, pos);
	else
		sort_3(data, pos);
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
