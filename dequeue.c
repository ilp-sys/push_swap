/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:10:16 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/15 23:56:11 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*popped;
	return (popped);
}

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*popped;
	return (popped);
}

void	operation_swap(t_list **stack)
{
	t_list *popped1;
	t_list *popped2;

	popped1 = ft_lstpop_back(stack);
	popped2 = ft_lstpop_back(stack);
	ft_lstadd_back(stack, popped1);
	ft_lstadd_back(stack, popped2);
}

void	operation_push(t_list **src_list **dst)
{
	t_list	*popped;

	popped = ft_lstpop_back(src);
	ft_lstadd_back(dst, popped);
}

void	operation_rotate(t_list **stack)
{
	t_list	*popped;

	popped = ft_lstpop_back(stack);
	ft_lstadd_front(stack, popped);
}

void	operation_reverse_rotate(t_list **stack)
{
	t_list	*popped;

	popped = ft_lstpop_front(stack);
	ft_lstadd_back(popped);
}

#include <stdio.h>
void	show_menu()
{
	printf(" 1. swap a\n");
	printf(" 2. swap b\n");
	printf(" 3. swap a and swap b\n");
	printf(" 4. push a\n");
	printf(" 5. push b\n");
	printf(" 6. rotate a\n");
	printf(" 7. rotate b\n");
	printf(" 8. rotate a and rotate b\n");
	printf(" 9. reverse rotate a\n");
	printf("10. reverse rotate b\n");
	printf("11. reverse rotate a and reverse rotate b\n");
	printf("12. exit\n");
	printf(">>");
}

void	print_stacks(t_list *stack_a, t_list *stack_b)
{
	printf("\n[STACK_A] ")
	while (stack_a)
	{
		printf("%d ", stack_a->content);
		stack_a = stack_a->next;
	}
	printf("\n[STACK_B] ");
	while (stack_b)
	{
		printf("%d ", stack_b->content);
		stack_b = stack_b->next;
	}
	printf("\n");
}

int main()
{
	t_list	*stack_a;
	t_list	*stack_b;

	int flag = 1;
	while (flag)
	{
		show_menu();
		int input;
		scanf("%d", &input);
		switch(input)
		{
			//fill cases
		}
		print_stacks(stack_a, stack_b);
	}
	return (0);
}
