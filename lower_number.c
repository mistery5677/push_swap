/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:57:04 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/12 13:08:55 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_distance(t_stack *stack, int number)
{
	t_stack	*tmp_stack;
	int		i;
	int		stack_size;

	tmp_stack = stack;
	stack_size = ft_stacksize(tmp_stack);
	i = 0;
	while (tmp_stack->number != number)
	{
		tmp_stack = tmp_stack->next;
		i++;
	}
	if (i > stack_size / 2)
	{
		i = -1;
		while (tmp_stack != NULL)
		{
			tmp_stack = tmp_stack->next;
			i++;
		}
	}
	return (i);
}

int	find_stack(t_stack *stack_a, t_stack *stack_b, int minimum)
{
	t_stack	*tmp_stacka;
	t_stack	*tmp_stackb;

	tmp_stacka = stack_a;
	tmp_stackb = stack_b;
	while (tmp_stacka != NULL)
	{
		if (tmp_stacka->number == minimum)
			return (1);
		tmp_stacka = tmp_stacka->next;
	}
	while (tmp_stackb != NULL)
	{
		if (tmp_stackb->number == minimum)
			return (2);
		tmp_stackb = tmp_stackb->next;
	}
	return (0);
}
