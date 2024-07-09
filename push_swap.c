/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/08 12:54:29 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	create_stack(&stack_a, argc, argv);
	if(check(argc, argv) == 0 && argc > 2)
	{
		if(sort(stack_a))
			ft_printf("Sorted\n");
		else if(ft_stacksize(stack_a) == 2)
		{
			if(stack_a->number > stack_a->next->number)
				move_swap(&stack_a, "sa\n");
		}
		else if (!sort(stack_a))
			sort_stack(&stack_a, &stack_b);
	}
	else
		ft_printf("Error\n");
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