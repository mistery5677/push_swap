/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:36:21 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/13 02:15:37 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		if (tmp != NULL && tmp->number == stack->number)
			return (1);
	}
	return (0);
}

static int	check_limit(char *argv)
{
	if (ft_strncmp(argv, "2147483647", 11) > 0 && ft_strlen(argv) == 10)
		return (1);
	else if (argv[0] == '-')
		if (ft_strncmp(argv, "-2147483648", 11) > 0 && ft_strlen(argv) == 11)
			return (1);
	return (0);
}

static int	check_letters(char *argv)
{
	size_t	i;

	i = 0;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	if (ft_strlen(argv) == i || argv[i] < '0' || argv[i] > '9')
		return (1);
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
		{
			if (argv[i] != ' ')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check(t_stack *stack, char **argv)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 1;
	if (ft_stacksize(stack) <= 1)
		return (1);
	while (argv[i] && stack != NULL)
	{
		if (check_doubles(tmp) == 1 || check_limit(argv[i]) == 1
			|| check_letters(argv[i]))
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
