/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:42:28 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/17 18:32:52 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stack(int *data, t_list **stack_a, t_list **stack_b)
{
	while (data)
	{

	}
	*stack_b = NULL;
}

int main(int argc, char *argv[])
{
	int		*data;
	t_list	*stack_a;
	t_list	*stack_b;

	data = parsing(argc, argv);
	initialize_stack(data, &stack_a, &stack_b);
	push_swap(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
