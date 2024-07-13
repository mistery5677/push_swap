/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:53:38 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/13 02:19:53 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	node_number(t_stack **stack, int n2)
{
	int		nbr2;
	t_stack	*copy;
	int		i;

	i = 0;
	copy = *stack;
	if (copy == NULL)
		return (0);
	nbr2 = 0;
	while (i < n2)
	{
		copy = copy->next;
		i++;
	}
	nbr2 = copy->number;
	return (nbr2);
}

int	node_temp(t_stack **stack, int n2)
{
	int		nbr2;
	int		i;
	t_stack	*copy;

	i = 0;
	copy = *stack;
	if (copy == NULL)
		return (0);
	nbr2 = 0;
	while (i < n2)
	{
		copy = copy->next;
		i++;
	}
	nbr2 = copy->temp;
	return (nbr2);
}

void	parse(char *str, t_stack **stack_a)
{
	char	*tmp;
	int		i;
	int		x;

	tmp = NULL;
	i = 0;
	x = i;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i + 1] == 0)
		{
			tmp = ft_substr(str, x, i);
			x = i + 1;
			create_node(stack_a, tmp);
			free(tmp);
		}
		i++;
	}
}

int	verify_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}
