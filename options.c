/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 16:13:14 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/05 16:13:32 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	many_rr(t_stack *stack_a, t_stack *stack_b)
{
	int	ra;
	int	rb;
	int	rr;

	rr = 0;
	ra = stack_a->r_move;
	rb = stack_b->r_move;
	while (ra > 0 && rb > 0)
	{
		ra--;
		rb--;
		rr++;
	}
	return (rr + ra + rb);
}

void	option_1(t_stack **stack_a, t_stack **stack_b, int ra, int rrb)
{
	while (ra > 0)
	{
		move_reverse(stack_a, "ra\n");
		ra--;
	}
	while (rrb > 0)
	{
		move_rreverse(stack_b, "rrb\n");
		rrb--;
	}
	move_push(stack_a, stack_b, "pa\n");
}

void	option_2(t_stack **stack_a, t_stack **stack_b, int rra, int rb)
{
	while (rra > 0)
	{
		move_rreverse(stack_a, "rra\n");
		rra--;
	}
	while (rb > 0)
	{
		move_reverse(stack_b, "rb\n");
		rb--;
	}
	move_push(stack_a, stack_b, "pa\n");
}

void	option_3(t_stack **stack_a, t_stack **stack_b, int ra, int rb)
{
	while (ra > 0 && rb > 0)
	{
		move_reverse(stack_a, "r");
		move_reverse(stack_b, "r\n");
		ra--;
		rb--;
	}
	while (ra > 0)
	{
		move_reverse(stack_a, "ra\n");
		ra--;
	}
	while (rb > 0)
	{
		move_reverse(stack_b, "rb\n");
		rb--;
	}
	move_push(stack_a, stack_b, "pa\n");
}

void	option_4(t_stack **stack_a, t_stack **stack_b, int rra, int rrb)
{
	while (rra > 0 && rrb > 0)
	{
		move_rreverse(stack_a, "rr");
		move_rreverse(stack_b, "r\n");
		rra--;
		rrb--;
	}
	while (rra > 0)
	{
		move_rreverse(stack_a, "rra\n");
		rra--;
	}
	while (rrb > 0)
	{
		move_rreverse(stack_b, "rrb\n");
		rrb--;
	}
	move_push(stack_a, stack_b, "pa\n");
}
