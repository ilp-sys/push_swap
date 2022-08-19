/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:15:51 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/19 20:49:08 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_error_exit()
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_split(char **splitted)
{
	int i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

void	print_ops(t_list *lst)
{
	if (lst->content == sa)
		write(1, "sa\n", 3);
	else if (lst->content == sb)
		write(1, "sb\n", 3);
	else if (lst->content == ss)
		write(1, "ss\n", 3);
	else if (lst->content == pa)
		write(1, "pa\n", 3);
	else if (lst->content == pb)
		write(1, "pb\n", 3);
	else if (lst->content == ra)
		write(1, "ra\n", 3);
	else if (lst->content == rb)
		write(1, "rb\n", 3);
	else if (lst->content == rr)
		write(1, "rr\n", 3);
	else if (lst->content == ra)
		write(1, "rra\n", 4);
	else if (lst->content == rb)
		write(1, "rrb\n", 4);
	else if (lst->content == rrr)
		write(1, "rrr\n", 4);
}
