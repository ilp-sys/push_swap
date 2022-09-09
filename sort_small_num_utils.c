/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_num_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:54:01 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 21:55:08 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_type(t_node *start_node)
{
	const int	num1 = start_node->content;
	const int	num2 = start_node->prev->content;
	const int	num3 = start_node->prev->prev->content;

	if (num1 < num2 && num1 < num3)
	{
		if (num2 < num3)
			return (0);
		else
			return (1);
	}
	else if (num2 < num1 && num2 < num3)
	{
		if (num1 < num3)
			return (1);
		else
			return (2);
	}
	else
	{
		if (num1 < num2)
			return (3);
		else
			return (1);
	}
}

void	sort_small_num(t_data data, size_t high, size_t low, int pos)
{
	if (high - low == 0)
		return ;
	else if (high - low == 1)
		sort_1(data, pos);
	else if (high - low == 2)
		sort_2(data, pos);
	else if (high - low == 3)
		sort_3(data, pos);
	else
		sort_4(data, pos);
}
