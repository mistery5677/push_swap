/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/24 21:55:38 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (!sort(stack_a))
	{
			sort_stack(&stack_a, &stack_b);
	}
	while(stack_a != NULL)
	{
		printf("number %d	r %d	rr %d 	together %d 	bf %d\n", stack_a->number, stack_a->r_move,  stack_a->rr_move, stack_a->move_together, stack_a->bf);
		stack_a = stack_a->next;
	}
	while(stack_b != NULL)
	{
		printf("number %d	r %d	rr %d 	together %d 	bf %d\n", stack_b->number, stack_b->r_move,  stack_b->rr_move, stack_b->move_together, stack_b->bf);
		stack_b = stack_b->next;
	}
	free_stack(stack_a);
	free_stack(stack_b);
}
// Corrigir a parte de se já for o maior numero possivel e o menor numero possivel

/* 


1
5
9
	3
	-1
	0
	4
	8
	2

*/