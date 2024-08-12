/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:13:00 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/12 22:33:52 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	update_moves(int a, int b)
{
	int	a_b;

	a_b = 0;
	while (a > 0 && b > 0)
	{
		a--;
		b--;
		a_b++;
	}
	return (a_b);
}

int	move_together(int ra, int rra, int rb, int rrb)
{
	int	rr;
	int	rrr;
	int	rarrb;
	int	rrarb;

	rarrb = ra + rrb;
	rrarb = rra + rb;
	rr = update_moves(ra, rb);
	rrr = update_moves(rra, rrb);
	ra = ra - rr;
	rra = rra - rrr;
	rb = rb - rr;
	rrb = rrb - rrr;
	if (rarrb < rr + ra + rb && rarrb < rrr + rra + rrb && rarrb < rrarb)
		return (rarrb + 1);
	else if (rrarb < rr + ra + rb && rrarb < rrr + rra + rrb && rrarb < rarrb)
		return (rrarb + 1);
	else if (rr + ra + rb <= rrr + rra + rrb)
		return (rr + ra + rb + 1);
	else
		return (rrr + rra + rrb + 1);
}
