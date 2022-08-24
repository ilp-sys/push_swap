/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:51:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/24 23:11:50 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"

# define DEFAULT_SIZE 3

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

typedef struct s_data
{
	t_deq	*queue_a;
	t_deq	*queue_b;
	t_deq	*ops;
}t_data;

//main.c
int		main(int argc, char *argv[]);

//parsing.c
int		ft_atoi_protected(const char *str);
int		check_argument(t_deq *stack_a, char *str);
void	get_input(int argc, char *argv[], t_deq *stack_a);
void	free_split(char **splitted);

//push_swap.c
void	push_swap(t_deq *queue_a, t_deq *queue_b, t_deq *ops);
int		get_cubic_num(int size, int *pos);
void	init_data(t_deq *queue_a, t_deq *queue_b, t_deq *ops, t_data *data);
void	design_division(int size, int cub_num, t_deq (*meta)[2]);
void 	divide(t_data data, t_deq (*meta)[2], int pos);
void	merge(t_data data, t_deq (*meta)[2], int pos);
void	sort3(t_data data);
void	sort4(t_data data);

//push_swap_utils.c
void	parse_err_exit();
void	print_ops(t_node *ops);

//queue_utils.c
t_node	*queue_pop_back(t_deq *queue);
t_node	*queue_pop_front(t_deq *queue);
void	queue_push_back(t_deq *queue, t_node *node);
void	queue_push_front(t_deq *queue, t_node *node);
t_node	*get_new_node(int content);
size_t	get_queue_size(t_deq *queue);
t_node	*get_last_node(t_deq *queue);
void	free_queue(t_deq **queue);
void	queue_init(t_deq **queue);

//operations.c
void	operation_swap(t_deq *queue);
void	operation_push(t_deq *src, t_deq *dst);
void	operation_rotate(t_deq *queue);
void	operation_reverse_rotate(t_deq *queue);
void	operate(t_deq *ops, int op, t_data data);

//adding_operation.c
void	append_to_ops(t_deq *ops, int op);
void	optimize_swap(t_deq *ops, int op);
void	optimize_push(t_deq *ops, int op);
void	optimize_rotate(t_deq *ops, int op);

#endif
