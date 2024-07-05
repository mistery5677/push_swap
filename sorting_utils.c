/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:14:03 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/05 16:14:08 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_distance(t_stack *stack, int number)
{
	t_stack	*tmp_stack;
	int		i;

	tmp_stack = stack;
	i = 0;
	while (tmp_stack != NULL && tmp_stack->number != number)
	{
		tmp_stack = tmp_stack->next;
		i++;
	}
	return (i);
}

void	count_moves(t_stack *stack)
{
	t_stack	*tmp_stack;
	int		moves;

	moves = 0;
	tmp_stack = stack;
	while (tmp_stack != NULL)
	{
		tmp_stack->move_together = 0;
		tmp_stack->r_move = moves;
		tmp_stack = tmp_stack->next;
		moves++;
	}
	tmp_stack = stack;
	while (moves > 0)
	{
		tmp_stack->rr_move = moves;
		moves--;
		tmp_stack = tmp_stack->next;
	}
}
