/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:55:19 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/06 19:02:15 by jiwahn           ###   ########.fr       */
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
	if (pos != A_TOP)
		move_to_a_top(data, pos);
}

void	sort_2(t_data data, int pos)
{
	int		i;
	t_node	*a_top;

	i = 0;
	if (pos != A_BTM && pos != A_TOP)
		while (i++ < 2)
			move_to_a_top(data, pos);
	a_top = get_last_node(data.stack[0]);
	if (a_top->content > a_top->prev->content)
	{
		operation_swap(data.stack[0]);
		append_to_ops(data.ops, sa);
	}
}

int	is_sorted_sort_3(t_data data, int pos)
{
	t_node	*start_node = get_start_node(data, pos);
	int num1 = start_node->content;
	start_node = get_next_node(start_node, pos);
	int num2 = start_node->content;
	start_node = get_next_node(start_node, pos);
	int num3 = start_node->content;

	printf("%d %d %d\n", num1, num2, num3);
	if ((pos == A_BTM && (num3 > num1 && num3 > num2)) || \
			(pos == A_TOP && (num1 > num2 && num1 > num3)))
	{
		printf("case 1\n");
		operation_rotate(data.stack[0]);
		append_to_ops(data.ops, ra);
		sort_2(data, A_TOP);
		return (-1);
	}
	else if (pos % 2 && (num3 > num2 && num3 > num1))
	{
		printf("case 2\n");
		if (pos == B_BTM)
			for (int i = 0; i < 3; i++)
				move_to_a_top(data, pos);
		if (num1 > num2)
		{
			operation_swap(data.stack[0]);
			append_to_ops(data.ops, sa);
		}
		return (-1);
	}
	else if (!(pos % 2) && (num1 > num2 && num1 > num3))
	{
		printf("case 3\n");
		if (pos == B_BTM)
			for (int i = 0; i < 3; i++)
				move_to_a_top(data, pos);
		if (num2 < num3)
		{
			operation_swap(data.stack[0]);
			append_to_ops(data.ops, sa);
		}
		return (-1);
	}
	else //return median
	{
		printf("case else\n");
		if ((num1 < num2 && num1 > num3) || (num1 > num2 && num1 < num3))
			return (num1);
		else if ((num2 > num1 && num2 < num3) || (num2 < num1 && num2 > num3))
			return (num2);
		else
			return (num3);
	}
}

int	is_sorted_sort_4(t_data data, int pos)
{
	int	ret_val;
	t_node	*start_node;
	int nums[4];

	ret_val = 0;
	start_node = get_start_node(data, pos);
	for(int i = 0; i < 4; i++)
	{
		nums[i] = start_node->content;
		start_node = get_next_node(start_node, pos);
	}
	if ((pos % 2) && (nums[0] < nums[1] && nums[0] < nums[2] && nums[0] < nums[3]))
	{
		if (nums[1] < nums[2] && nums[1] < nums[3])
			if (nums[2] < nums[3])
				ret_val = -1;
	}
	else if (!(pos % 2) && (nums[3] < nums[2] && nums[3] < nums[1] && nums[3] < nums[0]))
	{
		if (nums[2] < nums[1] && nums[2] < nums[0])
			if (nums[1] < nums[0])
				ret_val = -1;
	}
	return (ret_val);
}

void	sort_3(t_data data, int pos) //single pivot quick sort
{
	int	cnt;
	int	sorted;
	int median;
	t_node	*start_node;

	cnt = 0;
	start_node = get_start_node(data, pos);
	sorted = is_sorted_sort_3(data, pos);
	if (sorted == -1)
		return ;
	else
		median = sorted;

	for (int i = 0; i < 3; i++)
	{
		if (start_node->content >= median)
			cnt += move_to_a_top(data, pos);
		else
			cnt += move_to_b_top(data, pos);
		start_node = get_start_node(data, pos);
	}
	if (cnt)
		collect(data, pos, cnt); //collect in case of pos equals 1
	sort_2(data, 1);
	operation_push(data.stack[1], data.stack[0]);
	append_to_ops(data.ops, pa);
}

void	sort_4(t_data data, int pos) //single pivot quick sort
{
	t_node	*start_node;
	t_pair	pivot_v;

	if (is_sorted_sort_4(data, pos) == -1)
	{
		if (pos == B_TOP || pos == B_BTM)
		{
			for(int i = 0; i < 4; i++)
				move_to_a_top(data, pos);
		}
		return ;
	}
	start_node = get_start_node(data, pos);
	pivot_v = find_pivot(start_node, 0, 4, pos);
	for (int i = 0; i < 4; i++)
	{
		if (start_node->content > pivot_v.former)
		{
			if (pos != A_BTM)
			{
				move_to_a_top(data, pos);
			}
		}
		else
			move_to_b_top(data, pos);
		start_node = get_start_node(data, pos);
	}
	sort_2(data, A_TOP);
	for (int i = 0; i < 2; i++)
		move_to_a_top(data, 2);
	sort_2(data, A_TOP);
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
	if (argc > 1)
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
	print_queue(stack_a); 
	print_queue(stack_b); 
	return (0);
}
