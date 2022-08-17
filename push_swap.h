/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:45:30 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/17 18:48:28 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# include "libft/libft.h"

//push_swap_utils.c
t_list	*ft_lstpop_front(t_list **lst);
t_list	*ft_lstpop_back(t_list **lst);

//operations.c
void	operation_swap(t_list **stack);
void	operation_push(t_list **src, t_list **dst);
void	operation_rotate(t_list **stack);
void	operation_reverse_rotate(t_list **stack);

//main.c


#endif
