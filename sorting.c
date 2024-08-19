/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:14:45 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/19 18:58:10 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_b != NULL && ft_stacksize(*stack_a) != 3)
		move_push(stack_a, stack_b, "pa\n");
	while (!sort(*stack_a))
	{
		if (node_number(stack_a, 0) > node_number(stack_a, 1)
			&& node_number(stack_a, 0) > node_number(stack_a, 2))
			move_reverse(stack_a, "ra\n");
		if (node_number(stack_a, 0) > node_number(stack_a, 1))
			move_swap(stack_a, "sa\n");
		if (node_number(stack_a, 1) > node_number(stack_a, 2))
			move_rreverse(stack_a, "rra\n");
	}
}

int	find_minimum(t_stack *stack_a)
{
	t_stack	*tmp_stacka;
	int		minimum;

	tmp_stacka = stack_a;
	minimum = stack_a->number;
	while (tmp_stacka != NULL)
	{
		if (minimum > tmp_stacka->number)
			minimum = tmp_stacka->number;
		tmp_stacka = tmp_stacka->next;
	}
	return (minimum);
}

int	find_max(t_stack *stack_a)
{
	t_stack	*tmp_stacka;
	int		max;

	tmp_stacka = stack_a;
	max = stack_a->number;
	while (tmp_stacka != NULL)
	{
		if (max < tmp_stacka->number)
			max = tmp_stacka->number;
		tmp_stacka = tmp_stacka->next;
	}
	return (max);
}

void	final_sort(t_stack **stack_a, int minimum)
{
	t_stack	*tmp_stack;

	tmp_stack = *stack_a;
	while (tmp_stack != NULL && tmp_stack->number != minimum)
		tmp_stack = tmp_stack->next;
	if (tmp_stack->r_move < tmp_stack->rr_move)
	{
		while (tmp_stack->r_move > 0)
		{
			move_reverse(stack_a, "ra\n");
			tmp_stack->r_move--;
		}
	}
	else
	{
		while (tmp_stack->rr_move > 0)
		{
			move_rreverse(stack_a, "rra\n");
			tmp_stack->rr_move--;
		}
	}
}

int	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	minimum;
	int	max;

	max = find_max(*stack_a);
	minimum = find_minimum(*stack_a);
	if (push_b(stack_a, stack_b) == -1)
		return (-1);
	while (stack_b != NULL && *stack_b != NULL)
	{
		count_moves(*stack_a);
		count_moves(*stack_b);
		find_bf(*stack_a, *stack_b, minimum, max);
		if (ft_move(stack_a, stack_b) == -1)
			return (-1);
	}
	count_moves(*stack_a);
	final_sort(stack_a, minimum);
	return (0);
}
