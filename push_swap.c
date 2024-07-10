/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelcosta <miguelcosta@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/10 15:44:21 by miguelcosta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_all(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while(tmp != NULL)
	{
		printf("number %d r %d rr %d bf %d move_together %d\n", tmp->number, tmp->r_move, tmp->rr_move, tmp->bf, tmp->move_together);
		tmp = tmp->next;
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	create_stack(&stack_a, argc, argv);
	if(check(stack_a, argc, argv) == 0 && argc > 2)
	{
		if(sort(stack_a))
			ft_printf("Sorted\n");
		else if(ft_stacksize(stack_a) == 2)
		{
			if(stack_a->number > stack_a->next->number)
				move_swap(&stack_a, "sa\n");
		}
		else if(ft_stacksize(stack_a) == 3)
			ft_sort3(&stack_a, &stack_b);
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