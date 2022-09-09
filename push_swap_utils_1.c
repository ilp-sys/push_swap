/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:30:48 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/09 20:53:23 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_pair(t_pair *pair, int former, int latter)
{
	pair->former = former;
	pair->latter = latter;
}

t_pair	find_pivot(t_node *start_node, size_t low, size_t high, int pos)
{
	int		min;
	int		min_idx;
	t_pair	pivot_v;
	t_pair	idx;
	t_node	*cur_node;
	int		dsc_ord[high - low];
	int		marked[high - low];

	idx.former = 0;
	for (int i = 0; i < (int)(high - low); i++)
		marked[i] = 0;
	while (idx.former < (int)(high - low))
	{
		min = INT_MAX;
		min_idx = -1;
		idx.latter = 0;
		cur_node = start_node;
		while (idx.latter < (int)(high - low))
		{
			if (marked[idx.latter] == 1)
				;
			else if (cur_node->content <= min)
			{
				min = cur_node->content;
				min_idx = idx.latter;
			}
			cur_node = get_next_node(cur_node, pos);
			idx.latter++;
		}
		marked[min_idx] = 1;
		dsc_ord[idx.former++] = min;
	}
	set_pair(&pivot_v, dsc_ord[(high - low) / 3 * 1], dsc_ord[(high - low) / 3 * 2]);
	return (pivot_v);
}
