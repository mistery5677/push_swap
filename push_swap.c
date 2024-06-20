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
		if(ft_stacksize(stack_a) == 3)
			ft_sort3(&stack_a, &stack_b);
		else
			sort_stack(&stack_a, &stack_b);
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