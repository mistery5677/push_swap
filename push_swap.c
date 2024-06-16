/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/12 15:40:17 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int midium)
{
	int	minimum;
	int	found;
	static int flag;

	minimum = lower_number(*stack_a, *stack_b);
	if (flag == 0)
	{
		flag ++;
		minimum = first_lower(*stack_a);
	}
	found = find_stack(*stack_a, *stack_b, minimum);
	if (found == 1)
		ft_sort_stacka(stack_a, stack_b, minimum, midium);
	else if (found == 2)
		ft_sort_stackb(stack_b, stack_a, minimum);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int midium;

	midium = ft_midium(stack_a); 
	if (!sort(stack_a))
	{
		move_push(&stack_b, &stack_a);
		while (!sort(stack_a) || stack_b != NULL)
			sort_stack(&stack_a, &stack_b, midium);
	}
	free_stack(stack_a);
}

/* 
	4
	3
	2
	1
	0
	9
	8
	7
	6





1  4 6 8 11 16*/