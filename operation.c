/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:01:40 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/18 11:01:41 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void operation_swap(t_list **stack)
{
    t_list *popped1;
    t_list *popped2;

    popped1 = ft_lstpop_back(stack);
    popped2 = ft_lstpop_back(stack);
    ft_lstadd_back(stack, popped1);
    ft_lstadd_back(stack, popped2);
}

void    operation_push(t_list **src, t_list **dst)
{
    t_list  *popped;

    popped = ft_lstpop_back(src);
    ft_lstadd_back(dst, popped);
}

void    operation_rotate(t_list **stack)
{
    t_list  *popped;

    popped = ft_lstpop_back(stack);
    ft_lstadd_front(stack, popped);
}

void    operation_reverse_rotate(t_list **stack)
{
    t_list  *popped;

    popped = ft_lstpop_front(stack);
    if (popped != NULL)
        popped->next = NULL;
    ft_lstadd_back(stack, popped);
}
