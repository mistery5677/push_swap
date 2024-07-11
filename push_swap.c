/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/12 00:24:14 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_4_5(t_stack **stack_a, t_stack **stack_b)
{
	int	max;
	int	minimum;

	max = find_max(*stack_a);
	minimum = find_minimum(*stack_a);
	while (ft_stacksize(*stack_a) != 3)
		move_push(stack_b, stack_a, "pb\n");
	ft_sort3(stack_a, stack_b);
	while (stack_b != NULL && *stack_b != NULL)
	{
		count_moves(*stack_a);
		count_moves(*stack_b);
		find_bf(*stack_a, *stack_b, minimum, max);
		ft_move(stack_a, stack_b);
	}
	count_moves(*stack_a);
	final_sort(stack_a, minimum);
}

static void	first_sort(t_stack **stack_a, t_stack **stack_b)
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
		sort_4_5(stack_a, stack_b);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	create_stack(&stack_a, argc, argv);
	if (check(stack_a, argc, argv) == 0 && argc > 2)
	{
		if (sort(stack_a))
			ft_printf("Sorted\n");
		else if (ft_stacksize(stack_a) <= 5)
			first_sort(&stack_a, &stack_b);
		else if (!sort(stack_a))
			sort_stack(&stack_a, &stack_b);
	}
	else
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
