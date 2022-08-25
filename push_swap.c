/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:10:45 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/25 17:07:17 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cubic_num(int size, int *pos)
{
	int	cub_num;

	cub_num = 1;
	*pos = 0;
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

void	divide(t_data data, t_deq (*meta)[2], int pos)
{
	//divide a whole stack into sorted small triangles
	//in accordance with the meta stack
	while (meta[pos]) //iterate while the meta pointer exist
	{
		//TODO - quick sort here
		//keep appeding to pos queue
		meta[pos] = meta[pos]->next;
	}
}

void	move_to_otherside(t_data data, t_deq (*meta)[2], int size, int pos)
{
	int		sum;
	t_node	*head;

	while (size--) //set meta data
		operation_push(meta[pos], meat[!pos]);
	sum = 0;
	head = meta[!pos].head
	while (head)
	{
		sum += head->content;
		head = head->next;
	}
	while (sum--) //set actual data
	{
		if (pos)
		{
			operation_push(data.queue_b, data.queue_a);
			append_to_ops(pa);
		}
		else
		{
			operation_push(data.queue_a, data.queue_b);
			append_to_ops(pb);
		}
	}
}

int		get_smallest(long long num1, long long num2, long long num3)
{
	if (num1 < num2 && num1 < num3)
		return (1);
	else if (num2 < num1 && num2 < num3)
		return (2);
	else
		return (3);
}

void	merge(t_data data, t_deq (*meta)[2], int pos)
{
	int		size;
	int		sum;
	t_node	*data_last;

	size = get_queue_size(meta[pos]) / 3;
	//move one third of current stack and this could be a tmp memory
	move_to_otherside(data, meta, size, pos);

	//and merge to the back of the other stack
	//refer to the meta data, be aware of the memeory management while updating
	while (size--)
	{
		t_node	*cur_top = get_last_node(meta[pos]);
		t_node	*cur_bottom = meta[pos].head;
		t_node	*other_bottom = meta[!pos].head;
		sum = cur_top->content + cur_bottom->content + other_bottom->content;
		while (cur_top->content && cur_bottom->content && other_bottom->content)
		{
		}
		while (cur_top->content && cur_bottom->content)
		{
		}
		while (cur_top->content && other_bottom->content)
		{
		}
		while (cur_bottom->content && other_bottom->content)
		{
		}
		while (cur_top->content)
		{
		}
		while (cur_bottom->content)
		{
		}
		while (other_bottom->content)
		{
		}
		queue_pop_front(meta[pos]);
		queue_pop_back(meta[pos]);
		queue_pop_front(meta[!pos]);
		queue_push_back(meta[!pos], get_new_node(sum));
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

