/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/25 11:49:05 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cubic_num(int size, int *pos)
{
	int	cub_num;

	cub_num = 1;
	*pos = 1;
	while (cub_num < (size / 3))
	{
		cub_num *= 3;
		*pos = !(*pos);
	}
	return (cub_num);
}

void	init_data(t_deq *queue_a, t_deq *queue_b, t_deq *ops, t_data *data)
{
	data->queue_a = queue_a;
	data->queue_b = queue_b;
	data->ops = ops;
}

//TODO
void	divide(t_data data, t_deq (*meta)[2], int pos)
{
	//divide a whole stack into sorted small triangles
	//in accordance with the meta stack
	while (meta[pos]) //iterate while the meta pointer exist
	{
		if (meta[pos]->content == DEFAULT_SIZE)
			sort3(data);
		else if (meta[pos]->content == DEFAULT_SIZE + 1)
			sort4(data);
		meta[pos] = meta[pos]->next;
	}
}

void	design_division(int size, int cub_num, t_deq (*meta)[2], int pos)
{
	int	quotient;
	int	remainder;

	quotient = size / cub_num;
	remainder = size % cub_num;
	while (cub_num--)
	{
		if (remainder--)
			queue_push_back(meta[pos], get_new_node(quotietnt + 1));
		else
			queue_push_back(meta[pos], get_new_node(quotient));
	}
}

void	move_to_otherside(t_data data, int size, int pos)
{
	while (size--)
	{
		if (pos)
		{
			operation_push(data.queue_a, data.queue_b);
			append_to_ops(pb);
		}
		else
		{
			operation_push(data.queue_b, data.queue_a);
			append_to_ops(pa);
		}
	}
}

void	get_smallest(int num1, int num2, int num3)
{
}


void	merge(t_data data, t_deq (*meta)[2], int pos)
{
	int	size;

	if (!pos)
		size = get_queue_size(data.queue_a);
	else
		size = get_queue_size(data.queue_b);
	//move one third of current stack and this could be a tmp memory
	size /= 3;
	move_to_otherside(data, size, pos);
	//and merge to the back of the other stack
	//refer to the meta data, be aware of the memeory management while updating
	while (size--)
	{

	}
}

//data structure of index 0 is always a queue_a and so on
void	push_swap(t_deq *queue_a, t_deq *queue_b, t_deq *ops)
{
	int		size;
	int		cub_num; //the number of initial segment 
	int 	pos; //position where merger happens
	t_data	data; //queue_a + queue_b + ops deq
	t_deq	(*meta)[2]; //meta data to build triangle

	size = get_queue_size(queue_a);
	cub_num = get_cubic_num(size, &pos);
	init_queue(meta[0]);
	init_queue(meta[1]);
	init_data(queue_a, queue_b, ops, &data);
	design_division(size, cubnnum, &meta, pos) //design triangles for merger
	divide(data, meta, pos); //divide into initial segments
	while (cub_num /= 3)
	{
		merge(data, meta, pos); //updata meta here
		pos = !pos;
	}
}

