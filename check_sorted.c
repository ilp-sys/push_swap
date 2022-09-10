/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:01:23 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/10 19:29:41 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_sort_4(t_data data, int pos)
{
	int		i;
	int		flag;
	int		nums[4];
	t_node	*start_node;

	i = 0;
	flag = 0;
	start_node = get_start_node(data, pos);
	while (i < 4)
	{
		nums[i++] = start_node->content;
		start_node = get_next_node(start_node, pos);
	}
	if ((pos == A_TOP) && \
			(nums[0] < nums[1] && nums[1] < nums[2] && nums[2] < nums[3]))
		flag = -1;
	else if ((pos != A_TOP) && \
		(nums[0] > nums[1] && nums[1] > nums[2] && nums[2] > nums[3]))
		flag = -1;
	if (flag && (pos == B_TOP || pos == B_BTM))
		move_to_iter(data, 4, pos, &move_to_a_top);
	return (flag);
}

int	is_sorted(t_data data)
{
	t_node	*start_node;

	start_node = data.stack[0]->head;
	while (start_node->next)
	{
		if (start_node->content < start_node->next->content)
			return (0);
		start_node = start_node->next;
	}
	return (1);
}
