/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:08:14 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/11 00:47:10 by mistery576       ###   ########.fr       */
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
		if (a->number == min && tmp_b->number == max && (a->move_together == 0
				|| move_together(a->r_move, a->rr_move, tmp_b->r_move,
					tmp_b->rr_move) < a->move_together))
			util_first(a, tmp_b);
		else if (a->number > tmp_b->number && tmp_b->number > last_a
			&& (a->move_together == 0 || move_together(a->r_move, a->rr_move,
					tmp_b->r_move, tmp_b->rr_move) < a->move_together))
			util_first(a, tmp_b);
		else if (a->number > tmp_b->number && a->number < last_a
			&& (a->move_together == 0 || move_together(a->r_move, a->rr_move,
					tmp_b->r_move, tmp_b->rr_move) < a->move_together))
			util_first(a, tmp_b);
		else if (a->move_together == 0)
			a->move_together = 1000000;
		tmp_b = tmp_b->next;
	}
}

void	find_bf(t_stack *a, t_stack *b, int minimum, int max)
{
	t_stack	*t_a;
	t_stack	*t_b;
	t_stack	*l_no;
	int		l_nb;

	t_a = a;
	t_b = b;
	l_nb = t_a->number;
	first_bf(t_a, b, minimum, max);
	l_no = t_a;
	t_a = t_a->next;
	while (t_a != NULL)
	{
		while (t_b != NULL)
		{
			if ((valid1(t_a, t_b, minimum, max) == 1
					&& (l_no->move_together > move_together(t_a->r_move,
							t_a->rr_move, t_b->r_move, t_b->rr_move)))
				|| valid2(t_a, t_b, l_no, l_nb) == 1)
				util_bf2(&l_no, t_a, t_b);
			t_b = t_b->next;
		}
		update_info(&t_a, &t_b, b, &l_nb);
	}
}
