/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/08/19 18:58:28 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sort_4_5(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	minimum;

	max = find_max(*stack_a);
	minimum = find_minimum(*stack_a);
	while (ft_stacksize(*stack_a) != 3)
	{
		if (move_push(stack_b, stack_a, "pb\n") == -1)
			return (-1);
	}
	ft_sort3(stack_a, stack_b);
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

static int	first_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_stacksize(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->number > (*stack_a)->next->number)
			move_swap(stack_a, "sa\n");
	}
	else if (size == 3)
		ft_sort3(stack_a, stack_b);
	else
	{
		if (sort_4_5(stack_a, stack_b) == -1)
			return (-1);
	}
	return (0);
}

static void	free_error(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	if (create_stack(&stack_a, argc, argv) == -1)
		ft_putstr_fd("Error\n", 2);
	else if (check(stack_a, argv) == 0)
	{
		if (!sort(stack_a))
		{
			if (ft_stacksize(stack_a) <= 5)
			{
				if (first_sort(&stack_a, &stack_b) == -1)
					return (free_error(stack_a, stack_b));
			}
			else if (sort_stack(&stack_a, &stack_b) == -1)
				return (free_error(stack_a, stack_b));
		}
	}
	else if (check(stack_a, argv) == 1)
		ft_putstr_fd("Error\n", 2);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	push_swap(stack_a, stack_b, argc, argv);
}
