/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwahn <jiwahn@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:10:47 by jiwahn            #+#    #+#             */
/*   Updated: 2022/08/19 20:49:45 by jiwahn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_atoi_protected(const char *str)
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
		result += (*str - '0')	* sign;
		if(!(result >= INT_MIN && result <= INT_MAX))
			parse_error_exit();
		str++;
	}
	if (*str != '\0')
		parse_error_exit();
	return ((int)result);
}

int	check_argument(void *content, t_list *stack_a)
{
	int	ret;

	ret = ft_atoi_protected(content);
	while (stack_a)
	{
		if (stack_a->content == ret)
			parse_error_exit();
		stack_a = stack_a->next;
	}
	return (ret);
}

void	initialize_stack(int argc, char *argv[], t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		j;
	int		content;
	char	**splitted;

	i = 1;
	while (i < argc)
	{
		splitted = ft_split(argv[i], ' ');
		j = 0;
		if (splitted[0] == NULL)
			parse_error_exit();
		while (splitted[j])
		{
			content = check_argument(splitted[j], *stack_a);
			ft_lstadd_front(stack_a, ft_lstnew(content));
			j++;
		}
		free_split(splitted);
		i++;
	}
	*stack_b = NULL;
}
