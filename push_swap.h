/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:51:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/23 17:22:11 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

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

typedef struct s_info
{
	t_node	*from;
	size_t	till;
}t_info;

//main.c
int		main(int argc, char *argv[]);

//parsing.c
int		ft_atoi_protected(const char *str);
int		check_argument(t_deq *stack_a, char *str);
void	queue_init(t_deq **queue);
void	get_input(int argc, char *argv[], t_deq *stack_a);
void	free_split(char **splitted);

//push_swap.c
void	push_swap(t_deq *queue_a, t_deq *queue_b, t_deq *ops);
void	build_right_bottom(t_deq *queue_a, *t_deq *queue_b);
void	build_right_top(t_deq *queue_a, *t_deq *queue_b);
void	build_left_bottom(t_deq *queue_a, *t_deq *queue_b);
void	merge(t_info info[3], t_deq *queue_a, t_deq *queue_b, int iter_count);

//push_swap_utils.c
void	parse_err_exit();
void	print_ops(t_node *ops);
size_t	sorted_ascend(t_deq *queue, int top);
size_t	sorted_descend(t_deq *queue, int top);
size_t	sum_sorted(t_info info[3]);
int		find_min(t_info info[3]);

//queue_utils.c
t_node	*queue_pop_back(t_deq *queue);
t_node	*queue_pop_front(t_deq *queue);
void	queue_push_back(t_deq *queue, t_node *node);
void	queue_push_front(t_deq *queue, t_node *node);
t_node	*get_new_node(int content);
size_t	get_queue_size(t_deq *queue);
t_node	*get_last_node(t_deq *queue);
//void	free_queue(t_deq **queue); - not needed, I guess?

//operations.c
void	operation_swap(t_deq *queue);
void	operation_push(t_deq *src, t_deq *dst);
void	operation_rotate(t_deq *queue);
void	operation_reverse_rotate(t_deq *queue);
void	append_to_ops(t_deq *ops, t_node *node);

#endif
