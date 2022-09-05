/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:55:19 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/05 22:33:24 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

#include <stdio.h>
void	print_queue(t_deq *deq)
{
	t_node 	*tmp;

	printf("[STACK(%d)] ", deq->size);
	tmp = deq->head;
	while (tmp)
	{
		printf("%d - ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

void	sort_1(t_data data, int pos)
{
	if (pos % 3 != 1)
		move_to_a_top(data, pos);
}

void	sort_2(t_data data, int pos)
{
	int		i;
	t_node	*a_top;

	i = 0;
	if (pos % 3 != 1)
		while (i++ < 2)
			move_to_a_top(data, pos);
	a_top = get_last_node(data.stack[0]);
	if (a_top->content > a_top->prev->content)
	{
		operation_swap(data.stack[0]);
		append_to_ops(data.ops, sa);
	}
}

void	sort_3(t_data data, int pos) //one pivot quick sort
{
	t_node	*start_node;

	start_node = get_start_node(data, pos);
}

void	sort_4(t_data data, int pos) //one pivot quick sort
{
	t_node	*start_node;
	t_pair	pivot_v;

	start_node = get_start_node(data, pos);
	pivot_v = find_pivot(start_node, 0, 4, pos);
	for (int i = 0; i < 4; i++)
	{
		if (start_node->content <= pivot_v.former)
			move_to_a_top(data, pos);
		else
			move_to_b_top(data, pos);
	}
	sort2(data, 1);
	for (int i = 0; i < 2; i++)
		move_to_a_top(data, pos);
	sort2(data, 1);
}

int	check_type(t_node *start_node)
{
	const int	num1 = start_node->content;
	const int	num2 = start_node->prev->content;
	const int	num3 = start_node->prev->prev->content;

	if (num1 < num2 && num1 < num3)
	{
		if (num2 < num3)
			return (0);
		else
			return (1);
	}
	else if (num2 < num1 && num2 < num3)
	{
		if (num1 < num3)
			return (1);
		else
			return (2);
	}
	else
	{
		if (num1 < num2)
			return (3);
		else
			return (1);
	}
}

/*
 * type0 = all sorted 
 * type1 = swap
 * type2 = rotate
 * type3 = reverse rotate
*/

void	sort_3(t_data data, int pos)
{
	int	i;
	int	type;

	i = 0;
	if (pos % 3 != 1)
		while (i++ < 3)
			move_to_a_top(data, pos);
	type = check_type(get_last_node(data.stack[0]));
	while (1)
	{
		if (type == 0)
			return ;
		else if (type == 1)
		{
			operation_swap(data.stack[0]);
			append_to_ops(data.ops, sa);
		}
		else if (type == 2) //이게 맞나
		{
			operation_rotate(data.stack[0]);
			append_to_ops(data.ops, ra);
			type = check_type(get_last_node(data.stack[0]));
			if (type == 0 && get_queue_size(data.stack[0]) == 3)
				return ;
			operation_push(data.stack[0], data.stack[1]);
			append_to_ops(data.ops, pb);
			operation_push(data.stack[0], data.stack[1]);
			append_to_ops(data.ops, pb);
			operation_reverse_rotate(data.stack[0]);
			append_to_ops(data.ops, rra);
			operation_push(data.stack[1], data.stack[0]);
			append_to_ops(data.ops, pa);
			operation_push(data.stack[1], data.stack[0]);
			append_to_ops(data.ops, pa);
		}
		else
		{
			if (get_queue_size(data.stack[0]) != 3)
			{
				operation_push(data.stack[0], data.stack[1]); //move top 2 to B
				append_to_ops(data.ops, pb);
				operation_push(data.stack[0], data.stack[1]);
				append_to_ops(data.ops, pb);
				operation_rotate(data.stack[0]); //move target to A btm
				append_to_ops(data.ops, ra);
				operation_push(data.stack[1], data.stack[0]); //revert to A 
				append_to_ops(data.ops, pa);
				operation_push(data.stack[1], data.stack[0]);
				append_to_ops(data.ops, pa);
			}
			operation_reverse_rotate(data.stack[0]); //move last to A top -- rra 
			append_to_ops(data.ops, rra);
		}
		type = check_type(get_last_node(data.stack[0]));
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
	else if (high - low == 3)
		sort_3(data, pos);
	else
		sort_4(data, pos);
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
	    if (ops->head)
		{
			while (ops->head->next) 			//print
				ops->head = ops->head->next;	//push front when you append
			while (ops->head)
			{
				print_ops(ops->head);
				ops->head = ops->head->prev;
			}
		}
	}
	printf("A_");
	print_queue(stack_a); 
	printf("B_");
	print_queue(stack_b); 
	return (0);
}
