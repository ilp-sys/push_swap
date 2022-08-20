/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:51:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/20 19:24:46 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

enum ops
{
	sa = 0,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}t_node;

typedef struct s_deq
{
	int		size;
	t_node	*head;
}t_deq;

//main.c
int		main(int argc, char *argv[]);

//parsing.c
int		ft_atoi_protected(const char *str);
int		check_argument(int content, t_deq *queue);
void	queue_init(int argc, char *argv[], t_deq *queue_a, t_deq *queue_b);

//push_swap.c
void	push_swap(t_deq *queue_a, t_deq *queue_b, t_deq *ops);
void	merge(t_deq *queue_a, t_deq *queue_b, t_deq *ops);

//queue_utils.c
t_node	*queue_pop_back(t_deq *queue);
t_node	*queue_pop_front(t_deq *queue);
void	queue_push_back(t_deq *queue, t_node *node);
void	queue_push_front(t_deq *queue, t_node *node);
t_node	*get_new_node(int content);

//push_swap_utils.c

//operations.c
void	operation_swap(t_deq *queue);
void	operation_push(t_deq *src, t_deq *dst);
void	operation_rotate(t_deq *queue);
void	operation_reverse_rotate(t_deq *queue);

#endif
