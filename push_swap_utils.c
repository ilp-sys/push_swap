/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:15:51 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/18 14:35:33 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_error_exit()
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' \
			|| c== '\f' || c == '\r' || c == ' ');
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
