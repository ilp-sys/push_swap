/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 19:00:49 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/20 20:30:38 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	print_deq(t_deq *deq)
{
	printf("\n[deq] size %d: ", deq->size);
	t_node	*head = deq->head;
	while (head)
	{
		printf("%d- ", head->content);
		head = head->next;
	}
}

void	print_deq_reverse(t_deq *deq)
{
	printf("\n[deq - reversed] size %d: ", deq->size);
	t_node	*head = deq->head;

	if (!head)
	{
		printf("\n\n");
		return ;
	}
	while (head->next)
		head = head->next;
	while (head)
	{
		printf("%d- ", head->content);
		head = head->prev;
	}
	printf("\n\n");
}

void	show_menu()
{
	printf("1. queue pop back\n");
	printf("2. queue pop front\n");
	printf("3. queue push back\n");
	printf("4. queue push front\n");
	printf("5. exit\n");
	printf(">>");
}

int main()
{
	t_deq	*deq = (t_deq *)malloc(sizeof(t_deq));
	int flag  = 1;

	deq->size = 0;
	deq->head = NULL;
	while (flag)
	{
		int input;
		show_menu();
		scanf("%d", &input);
		switch (input)
		{
			case 1: 
			{
				t_node *tmp = queue_pop_back(deq);
				if (tmp)
					printf("%d popped!\n", tmp->content);
				break;
			}
			case 2: 
			{
				t_node *tmp = queue_pop_front(deq);
				if (tmp)
					printf("%d popped!\n", tmp->content);
				break;
			}
			case 3: 
			{
				int content;
				printf("content: ");
				scanf("%d", &content);
				t_node	*new_node = get_new_node(content);
				queue_push_back(deq, new_node);
				break;
			}
			case 4: 
			{
				int content;
				printf("content: ");
				scanf("%d", &content);
				t_node	*new_node = get_new_node(content);
				queue_push_front(deq, new_node);
				break;
			}
			case 5: flag = 0; break;
		}
		print_deq(deq);
		print_deq_reverse(deq);
	}

	return (0);
}
