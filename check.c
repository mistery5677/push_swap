/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 02:36:21 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/19 18:58:21 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_doubles(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = stack;
	while (tmp2 != NULL)
	{
		tmp = tmp2;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
			if (tmp != NULL && tmp2->number == tmp->number)
				return (1);
		}
		tmp2 = tmp2->next;
	}
	return (0);
}

static int	check_limit(char *str)
{
	if (str[0] == '-')
	{
		if ((ft_strncmp(str, "-2147483648", 11) > 0 && ft_strlen(str) == 11)
			|| ft_strlen(str) > 11)
			return (1);
	}
	else if ((ft_strncmp(str, "2147483647", 10) > 0 && ft_strlen(str) == 10)
		|| ft_strlen(str) > 10)
		return (1);
	return (0);
}

static int	check_letters(char *argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		while (argv[i] == ' ')
			i++;
		if (argv[i] == '+' || argv[i] == '-')
			i++;
		while (ft_isdigit(argv[i]) == 1)
			i++;
		if (argv[i] != ' ' && i < ft_strlen(argv))
			return (1);
		i++;
	}
	return (0);
}

static int	parse_check(char *argv)
{
	size_t	i;
	int		x;
	char	*str;

	str = NULL;
	i = 0;
	x = 0;
	while (i < ft_strlen(argv))
	{
		if (argv[i] == '-')
			i++;
		while (argv[i] >= '0' && argv[i] <= '9')
			i++;
		str = ft_substr(argv, x, i - x);
		i++;
		x = i;
		if (check_limit(str) == 1 || !str)
		{
			free(str);
			return (1);
		}
		free(str);
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
	if (stack == NULL)
		return (1);
	while (argv[i] && stack != NULL)
	{
		if (check_doubles(tmp) == 1 || parse_check(argv[i]) == 1
			|| check_letters(argv[i]) == 1)
			return (1);
		i++;
		tmp = tmp->next;
	}
	return (0);
}
