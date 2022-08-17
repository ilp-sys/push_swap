/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 18:45:16 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/17 19:51:45 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void show_menu()
{
	printf("1. insert front\n");
	printf("2. insert back\n");
	printf("3. delete front\n");
	printf("4. delete back\n");
	printf("5. exit\n");
	printf(">>");
}

void print_list(t_list *stack)
{
	printf("\n");
	while (stack)
	{
		printf("%d- ", (int)stack->content);
		stack = stack->next;
	}
	printf("\n");
}

int main()
{
	int input;
	int flag = 1;
	t_list *stack = NULL;

	while (flag)
	{
		print_list(stack);
		show_menu();
		scanf("%d", &input);
		switch(input)
		{
			case 1:
			{
				int data;
				printf("data: ");
				scanf("%d", &data);
				t_list	*new = ft_lstnew(data);
				ft_lstadd_front(&stack, new);
				break;
			}
			case 2:
			{
				int data;
				printf("data: ");
				scanf("%d", &data);
				t_list	*new = ft_lstnew(data);
				ft_lstadd_back(&stack, new);
				break;
			}
			case 3:
			{
				t_list *popped = ft_lstpop_front(&stack);
				if (popped)
					printf("%d popped\n", (int)popped->content);
				break;
			}
			case 4:
			{
				t_list *popped = ft_lstpop_back(&stack);
				if (popped)
					printf("%d popped\n", (int)popped->content);
				break;
			}
			case 5: flag = 0; break;
		}
	}
}

