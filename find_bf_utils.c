/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bf_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:46:32 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/11 00:46:38 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	util_bf2(t_stack **lowest_node, t_stack *tmp_a, t_stack *tmp_b)
{
	(*lowest_node)->move_together = 0;
	(*lowest_node) = tmp_a;
	tmp_a->move_together = move_together(tmp_a->r_move, tmp_a->rr_move,
			tmp_b->r_move, tmp_b->rr_move);
	tmp_a->bf = tmp_b->number;
}

int	valid1(t_stack *tmp_a, t_stack *tmp_b, int minimum, int max)
{
	if (tmp_a->number == minimum && tmp_b->number == max)
		return (1);
	return (0);
}

int	valid2(t_stack *tmp_a, t_stack *tmp_b, t_stack *lowest_node,
		int last_nbr)
{
	if (tmp_b->number < tmp_a->number && tmp_b->number >= last_nbr
		&& (lowest_node->move_together > move_together(tmp_a->r_move,
				tmp_a->rr_move, tmp_b->r_move, tmp_b->rr_move)))
		return (1);
	else if (last_nbr > tmp_a->number && tmp_b->number < tmp_a->number
		&& (lowest_node->move_together > move_together(tmp_a->r_move,
				tmp_a->rr_move, tmp_b->r_move, tmp_b->rr_move)))
		return (1);
	return (0);
}

void	update_info(t_stack **stack_a, t_stack **stack_b, t_stack *b,
		int *last_nbr)
{
	(*stack_b) = b;
	*last_nbr = (*stack_a)->number;
	(*stack_a) = (*stack_a)->next;
}
