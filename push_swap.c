/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/17 03:09:31 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int move_higher;
	int move_lower;
	int size;

	size = ft_stacksize(*stack_a);
	move_higher = worth_up(*stack_a, *stack_b);
	move_lower = worth_down(*stack_a, *stack_b);
	if(move_higher < move_lower)
	{
		if (move_higher > size / 2)
		{
			move_higher = size - move_higher;
			while(move_higher > 0)
			{
				move_rreverse(stack_a);
				ft_printf("rra\n");
				move_higher--;
			}
			move_push(stack_b, stack_a);
		}
		else
		{
			while(move_higher > 0)
			{
				move_reverse(stack_a);
				ft_printf("ra\n");
				move_higher--;
			}
			move_push(stack_b, stack_a);
		}
	}
	else
	{
		if (move_lower > size / 2)
		{
			move_lower = size - move_lower;
			while(move_lower > 0)
			{
				move_rreverse(stack_a);
				ft_printf("rrb\n");
				move_lower--;
			}
			move_push(stack_b, stack_a);
			move_reverse(stack_b);
			ft_printf("pb\nrb\n");
		}
		else
		{
			while(move_lower > 1)
			{
				move_reverse(stack_a);
				ft_printf("rb\n");
				move_higher--;
			}
			move_push(stack_b, stack_a);
			move_reverse(stack_b);
			ft_printf("pb\nrb\n");
		}
	}
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (!sort(stack_a))
	{
/* 		while (!sort(stack_a) || stack_b != NULL)
			sort_stack(&stack_a, &stack_b); */
		ft_printf("stack a\n");
		print_stack(&stack_b);
		// ft_printf("stack b\n");
		// print_stack(&stack_b);
		// sort_stack(&stack_a, &stack_b);
		// ft_printf("stack a depois\n");
		// print_stack(&stack_a);
		// ft_printf("stack b depois\n");
		// print_stack(&stack_b);
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