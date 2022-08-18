/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:45:30 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/18 15:05:53 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"

//push_swap_utils.c
void	parse_error_exit();
int		ft_isspace(int c);
void	free_split(char **splitted);

//parsing.c
int		ft_atoi_protected(const char *str);
int		check_argument(void *context, t_list *stack_a);
void	initialize_stack(int argc, char *argv[], t_list **stack_a, t_list **stack_b);

//list_pop.c
t_list	*ft_lstpop_front(t_list **lst);
t_list	*ft_lstpop_back(t_list **lst);

//operations.c
void	operation_swap(t_list **stack);
void	operation_push(t_list **src, t_list **dst);
void	operation_rotate(t_list **stack);
void	operation_reverse_rotate(t_list **stack);

//push_swap.c
void	push_swap(t_list **stack_a, t_list **stack_b);

//main.c
int		main(int argc, char *argv[]);

#endif
