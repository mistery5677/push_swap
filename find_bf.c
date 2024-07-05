/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:08:14 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/05 21:42:11 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	util_first(t_stack *a, t_stack *b)
{
	a->move_together = move_together(a->r_move, a->rr_move, b->r_move,
			b->rr_move);
	a->bf = b->number;
}

static void	first_bf(t_stack *a, t_stack *b, int min, int max)
{
	t_stack	*tmp_b;
	int		last_a;

	tmp_b = b;
	last_a = node_number(&a, ft_stacksize(a) - 1);
	while (tmp_b != NULL)
	{
		if (a->number == min && b->number == max)
			util_first(a, tmp_b);
		else if (a->number > b->number && b->number > last_a
			&& (a->move_together == 0 || move_together(a->r_move, a->rr_move,
					tmp_b->r_move, tmp_b->rr_move) < a->move_together))
			util_first(a, tmp_b);
		else if (a->number > b->number && a->number < last_a
			&& (a->move_together == 0 || move_together(a->r_move, a->rr_move,
					tmp_b->r_move, tmp_b->rr_move) < a->move_together))
			util_first(a, tmp_b);
		else if (a->move_together == 0)
			a->move_together = 1001000;
		tmp_b = tmp_b->next;
	}
}

static void	util_bf2(t_stack **lowest_node, t_stack *tmp_a, t_stack *tmp_b)
{
	(*lowest_node)->move_together = 0;
	(*lowest_node) = tmp_a;
	tmp_a->move_together = move_together(tmp_a->r_move, tmp_a->rr_move,
			tmp_b->r_move, tmp_b->rr_move);
	tmp_a->bf = tmp_b->number;
}

static void	util_bf(t_stack *tmp_a, t_stack *tmp_b, t_stack **lowest_node,
		int minimum, int max, int last_nbr)
{
	while (tmp_b != NULL)
	{
		if (tmp_a->number == minimum && tmp_b->number == max
			&& ((*lowest_node)->move_together > move_together(tmp_a->r_move,
					tmp_a->rr_move, tmp_b->r_move, tmp_b->rr_move)))
			util_bf2(lowest_node, tmp_a, tmp_b);
		else if (tmp_b->number < tmp_a->number && tmp_b->number >= last_nbr
			&& ((*lowest_node)->move_together > move_together(tmp_a->r_move,
					tmp_a->rr_move, tmp_b->r_move, tmp_b->rr_move)))
			util_bf2(lowest_node, tmp_a, tmp_b);
		else if (last_nbr > tmp_a->number && tmp_b->number < tmp_a->number
			&& ((*lowest_node)->move_together > move_together(tmp_a->r_move,
					tmp_a->rr_move, tmp_b->r_move, tmp_b->rr_move)))
			util_bf2(lowest_node, tmp_a, tmp_b);
		tmp_b = tmp_b->next;
	}
}

void	find_bf(t_stack *a, t_stack *b, int minimum, int max)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	t_stack	*lowest_node;
	int		last_nbr;

	tmp_a = a;
	tmp_b = b;
	last_nbr = tmp_a->number;
	first_bf(tmp_a, b, minimum, max);
	lowest_node = tmp_a;
	tmp_a = tmp_a->next;
	while (tmp_a != NULL)
	{
		tmp_b = b;
		util_bf(tmp_a, tmp_b, &lowest_node, minimum, max, last_nbr);
		last_nbr = tmp_a->number;
		tmp_a = tmp_a->next;
	}
}
