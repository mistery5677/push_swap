/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/11 13:34:16 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stacka(t_stack **stack_a, t_stack **stack_b, int minimum)
{
	t_stack	*tmp_stack;
	int		distance;

	tmp_stack = *stack_a;
	distance = 0;
	while (tmp_stack->number != minimum)
	{
		distance++;
		tmp_stack = tmp_stack->next;
	}
	while (distance > 0)
	{
		distance--;
		move_push(stack_b, stack_a);
		ft_printf("pb\n");
	}
	distance = ft_distance(*stack_a, minimum);
	move_reverse(stack_a);
	ft_printf("ra\n");
}

void	ft_sort_stackb(t_stack **stack_b, t_stack **stack_a, int minimum)
{
	t_stack	*tmp_stack;
	int		distance;
	int		size;

	size = ft_stacksize(*stack_b);
	tmp_stack = *stack_b;
	distance = 0;
	while (tmp_stack->number != minimum)
	{
		distance++;
		tmp_stack = tmp_stack->next;
	}
	if (distance > size / 2)
	{
		distance = size - distance;
		while (distance > 0)
		{
			distance--;
			move_rreverse(stack_b);
			ft_printf("rrb\n");
		}
		move_push(stack_a, stack_b);
		move_reverse(stack_a);
		ft_printf("pa\nra\n");
	}
	else
	{
		while (distance > 0)
		{
			distance--;
			move_reverse(stack_b);
			ft_printf("rb\n");
		}
		move_push(stack_a, stack_b);
		move_reverse(stack_a);
		ft_printf("pa\nra\n");
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	minimum;
	int	found;

	minimum = lower_number(*stack_a, *stack_b);
	found = find_stack(*stack_a, *stack_b, minimum);
	printf("minimum: %d    found: %d\n", minimum, found);
	if (found == 1)
		ft_sort_stacka(stack_a, stack_b, minimum);
	else if (found == 2)
		ft_sort_stackb(stack_b, stack_a, minimum);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (!sort(stack_a))
	{
		while (!sort(stack_a) || stack_b != NULL)
			sort_stack(&stack_a, &stack_b);
	}
	free_stack(stack_a);
}

/* 4
3
2
5
1

pb pb ra pa ra pa ra ra */