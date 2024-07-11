/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:14:03 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/12 00:41:28 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_distance(t_stack *stack, int number)
{
	t_stack	*tmp_stack;
	int		i;

	tmp_stack = stack;
	i = 0;
	while (tmp_stack != NULL && tmp_stack->number != number)
	{
		tmp_stack = tmp_stack->next;
		i++;
	}
	return (i);
}

void	count_moves(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		moves;

	moves = 0;
	tmp_stack = stack;
	while (tmp_stack != NULL)
	{
		tmp_stack->move_together = 0;
		tmp_stack->r_move = moves;
		tmp_stack = tmp_stack->next;
		moves++;
	}
	tmp_stack = stack;
	while (moves > 0)
	{
		tmp_stack->rr_move = moves;
		moves--;
		tmp_stack = tmp_stack->next;
	}
}

long long int	find_average(t_stack *stack_a)
{
	t_stack			*tmp;
	long long int	average;

	tmp = stack_a;
	average = 0;
	while (tmp != NULL)
	{
		average = average + tmp->number;
		tmp = tmp->next;
	}
	if (stack_a != NULL)
		return (average / ft_stacksize(stack_a));
	return (0);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	long long int	average;

	average = 0;
	while ((*stack_a) != NULL)
	{
		average = find_average(*stack_a);
		if ((*stack_a)->number > average)
			move_reverse(stack_a, "ra\n");
		else
			move_push(stack_b, stack_a, "pb\n");
		average = find_average(*stack_b);
		if ((*stack_b) != NULL && (*stack_b)->number < average)
			move_reverse(stack_b, "rb\n");
	}
	ft_sort3(stack_a, stack_b);
}
