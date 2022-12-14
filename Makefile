# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/09 14:00:43 by jiwahn            #+#    #+#              #
#    Updated: 2022/09/10 19:53:15 by jiwahn           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm
RMFLAGS = -rf

LIBFT_DIR = libft/
LIBFT_LIB = libft.a

SRCS = main.c adding_operation.c check_sorted.c sort_small_num.c \
	   push_swap.c move_to.c operations.c parsing.c push_swap_utils_1.c \
	   queue_utils_1.c check_sorted_sort_3.c execute_append.c \
	   push_swap_utils_2.c queue_utils_2.c sort_small_num_utils.c
	  
OBJ_DIR = obj/
OBJS = $(SRCS:.c=.o)

all : $(NAME)

clean : 
	@$(RM) $(RMFLAGS) $(OBJS)

fclean : clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(RM) $(RMFLAGS) $(NAME)

re: fclean all

$(NAME) : $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) re
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT_LIB) -o $@

$(OBJS) : $(SRCS)
	@$(CC) $(CFLAGS) $^ -c

.PHONY: all clean fclean re
