/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:10:16 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/17 17:33:59 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstpop_front(t_list **lst)
{
	t_list	*head;

	if (*lst == NULL)
		return (NULL);

	head = *lst;
	*lst = (*lst)->next;
	return (head);
}

t_list	*ft_lstpop_back(t_list **lst)
{
	t_list	*cur;
	t_list	*last;

	if (*lst == NULL)
		return (NULL);
	cur = *lst;
	last = cur->next;
	if (last == NULL)
	{
		last = cur;
		cur = NULL;
	}
	else
	{
		while (last->next)
		{
			cur = cur->next;
			last = cur->next;
		}
		cur->next = NULL;
	}
	return (last);
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

void	operation_push(t_list **src, t_list **dst)
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
	ft_lstadd_back(stack, popped);
}
