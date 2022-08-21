/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:08:41 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/21 17:00:55 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	queue_init(t_deq **queue)
{
	*queue = (t_deq *)malloc(sizeof(t_deq));
	(*queue)->size = 0;
	(*queue)->head = NULL;
}

void	free_split(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

int	ft_atoi_protected(const char *str)
{
	int			sign;
	long long	result;

	sign = 1;
	result = 0;
	while (*str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1; 
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += (*str - '0') * sign;
		if (!(result >= INT_MIN && result <= INT_MAX))
			parse_err_exit();
		str++;
	}
	if (*str != '\0')
		parse_err_exit();
	return ((int)result);
}

int	check_argument(t_deq *stack_a, char *str)
{
	int		num;
	t_node	*head;

	head = stack_a->head;
	num = ft_atoi_protected(str);
	while (head)
	{
		if (head->content == num)
			parse_err_exit();
		head = head->next;
	}
	return (num);
}

void	get_input(int argc, char *argv[], t_deq *stack_a)
{
	int		i;
	int		j;
	int		num;
	char	**splitted;

	i = 1;
	while (i < argc)
	{
		splitted = ft_split(argv[i], ' ');
		j = 0;
		if (splitted[j] == NULL)
			parse_err_exit();
		while (splitted[j])
		{
			num = check_argument(stack_a, splitted[j]);
			queue_push_front(stack_a, get_new_node(num));
			j++;
		}
		free_split(splitted);
		i++;
	}
}
