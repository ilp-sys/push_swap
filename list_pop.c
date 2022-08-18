/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 17:10:16 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/18 14:18:17 by jiwahn           ###   ########.fr       */
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
		*lst = NULL;
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
