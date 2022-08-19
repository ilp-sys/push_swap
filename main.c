/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:42:28 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/19 20:48:21 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*ops;

	if (argc < 2)
		return (0);
	ops = NULL;
	initialize_stack(argc, argv, &stack_a, &stack_b);
	push_swap(&stack_a, &stack_b, &ops);
	while (ops)
	{
		print_ops(ops);
		ops = ops->next;
	}
	ft_lstclear(&stack_a, NULL);
	ft_lstclear(&stack_b, NULL);
	ft_lstclear(&ops, NULL);
	return (0);
}
