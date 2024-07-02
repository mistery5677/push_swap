/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:53:38 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/11 11:54:58 by miafonso         ###   ########.fr       */
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
