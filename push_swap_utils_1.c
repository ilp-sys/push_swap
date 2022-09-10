/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:30:48 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/10 16:33:02 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pair(t_pair *pair, int former, int latter)
{
	pair->former = former;
	pair->latter = latter;
}

static t_pair	find_pivot_sort(t_node *start_node, int marked[], \
		int size, int pos)
{
	int		i;
	t_pair	min_info;
	t_node	*cur_node;

	min_info.former = INT_MAX;
	min_info.latter = -1;
	i = 0;
	cur_node = start_node;
	while (i < size)
	{
		if (marked[i] == 1)
			;
		else if (cur_node->content <= min_info.former)
		{
			min_info.former = cur_node->content;
			min_info.latter = i;
		}
		cur_node = get_next_node(cur_node, pos);
		i++;
	}
	return (min_info);
}

t_pair	find_pivot(t_node *start_node, int size, int pos)
{
	int		i;
	t_pair	min_info;
	t_pair	pivot_v;
	int		*dsc_ord;
	int		*marked;

	i = 0;
	dsc_ord = (int *)malloc(sizeof(int) * size);
	marked = (int *)malloc(sizeof(int) * size);
	while (i < size)
		marked[i++] = 0;
	i = 0;
	while (i < size)
	{
		min_info = find_pivot_sort(start_node, marked, size, pos);
		marked[min_info.latter] = 1;
		dsc_ord[i++] = min_info.former;
	}
	pivot_v.former = dsc_ord[size / 3 * 1];
	pivot_v.latter = dsc_ord[size / 3 * 2];
	free(dsc_ord);
	free(marked);
	return (pivot_v);
}
