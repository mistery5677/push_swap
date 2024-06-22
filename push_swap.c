/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/18 16:09:49 by miafonso         ###   ########.fr       */
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
		printf("number %d	ra %d	rra %d\n", stack_a->number, stack_a->ra_move,  stack_a->rra_move);
		stack_a = stack_a->next;
	}
	while(stack_b != NULL)
	{
		printf("number %d	ra %d	rra %d\n", stack_b->number, stack_b->ra_move,  stack_b->rra_move);
		stack_b = stack_b->next;
	}
	
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