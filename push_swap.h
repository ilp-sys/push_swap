/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 15:51:21 by jiwahn            #+#    #+#             */
/*   Updated: 2022/09/17 23:21:36 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"

enum e_pos
{
	A_BTM = 0,
	A_TOP,
	B_TOP,
	B_BTM
};

enum e_ops
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
	t_deq	*stack[2];
	t_deq	*ops;
}t_data;

typedef struct s_pair
{
	int	former;
	int	latter;
}t_pair;

//main.c
void	print_ops(t_node *ops);
void	print_ops_frame(t_deq ops);
int		main(int argc, char *argv[]);

//check_sorted.c
int		is_sorted(t_data data);
int		is_sorted_sort_4(t_data data, int pos);

//check_sorted_sort_3.c
int		is_sorted_sort_3(t_data data, int pos);

//sort_small_num.c
void	sort_1(t_data data, int pos);
void	sort_2(t_data data, int pos);
void	sort_3(t_data data, int pos);
void	sort_4(t_data data, int pos);

//sort_small_num_utils.c
int		check_type(t_node *start_node);
void	sort_small_num(t_data data, size_t high, size_t low, int pos);

//parsing.c
int		ft_atoi_protected(const char *str);
int		check_argument(t_deq *stack_a, char *str);
void	get_input(int argc, char *argv[], t_deq *stack_a);
void	free_split(char **splitted);

//move_to.c
size_t	move_to_iter(t_data data, int cnt, int pos, \
		size_t (*f)(t_data data, int pos));
size_t	move_to_a_top(t_data data, int pos);
size_t	move_to_b_top(t_data data, int pos);
size_t	move_to_b_btm(t_data data, int pos);

//push_swap.c
void	collect(t_data data, int pos, size_t cnt);
void	push_swap(t_deq *stack_a, t_deq *stack_b, t_deq *ops);
void	quick_sort(t_data data, size_t low, size_t high, int pos);
t_pair	partitioning(t_data data, size_t low, size_t high, int pos);

//push_swap_utils_1.c
void	set_pair(t_pair *pair, int former, int latter);
t_pair	find_pivot(t_node *start_node, int size, int pos);

//push_swap_utils_2.c
void	parse_err_exit(void);
t_data	init_data(t_deq *stack_a, t_deq *stack_b, t_deq *ops);
t_node	*get_start_node(t_data data, int pos);
t_node	*get_next_node(t_node *node, int pos);

//queue_utils_1.c
t_node	*queue_pop_back(t_deq *queue);
t_node	*queue_pop_front(t_deq *queue);
void	queue_push_back(t_deq *queue, t_node *node);
void	queue_push_front(t_deq *queue, t_node *node);

//queue_utils_1.c
t_node	*get_new_node(int content);
size_t	get_queue_size(t_deq *queue);
t_node	*get_last_node(t_deq *queue);
void	queue_init(t_deq **queue);

//operations.c
void	operation_swap(t_deq *queue);
void	operation_push(t_deq *src, t_deq *dst);
void	operation_rotate(t_deq *queue);
void	operation_reverse_rotate(t_deq *queue);

//adding_operation.c
void	append_to_ops(t_data data, int op);
void	optimize_swap(t_deq *ops, int op);
void	optimize_push(t_deq *ops, int op);
void	optimize_rotate(t_deq *ops, int op);

//execute_append.c
void	execute_append(t_data data, int op);

#endif
