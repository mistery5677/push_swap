/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:51:51 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/12 20:31:02 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	s_move(char *info, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) >= 2)
	{
		if (info[1] == 'a')
			move_swap(stack_a, "");
	}
	if (ft_stacksize(*stack_b) >= 2)
	{
		if (info[1] == 'b')
			move_swap(stack_b, "");
	}
	if (ft_stacksize(*stack_a) >= 2 && ft_stacksize(*stack_b) >= 2)
	{
		if (info[1] == 's')
		{
			move_swap(stack_a, "");
			move_swap(stack_b, "");
		}
	}
}

void	r_move(char *info, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) >= 2)
		if (info[1] == 'a')
			move_reverse(stack_a, "");
	if (ft_stacksize(*stack_b) >= 2)
		if (info[1] == 'b')
			move_reverse(stack_b, "");
	if (ft_stacksize(*stack_a) >= 2 && ft_stacksize(*stack_b) >= 2)
	{
		if (info[1] == 'r')
		{
			move_reverse(stack_a, "");
			move_reverse(stack_b, "");
		}
	}
}

void	rr_move(char *info, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) >= 2)
		if (info[2] == 'a')
			move_rreverse(stack_a, "");
	if (ft_stacksize(*stack_b) >= 2)
		if (info[2] == 'b')
			move_rreverse(stack_b, "");
	if (ft_stacksize(*stack_a) >= 2 && ft_stacksize(*stack_b) >= 2)
	{
		if (info[2] == 'r')
		{
			move_rreverse(stack_a, "");
			move_rreverse(stack_b, "");
		}
	}
}

void	p_move(char *info, t_stack **stack_a, t_stack **stack_b)
{
	if (stack_b != NULL && ft_stacksize(*stack_b) >= 1)
		if (info[1] == 'a')
			move_push(stack_a, stack_b, "");
	if (stack_a != NULL && ft_stacksize(*stack_a) >= 1)
		if (info[1] == 'b')
			move_push(stack_b, stack_a, "");
}

void	verify_info(char *info, t_stack **stack_a, t_stack **stack_b)
{
	if (info[0] == 's')
		s_move(info, stack_a, stack_b);
	else if (info[0] == 'r')
	{
		if (ft_strlen(info) == 3)
			r_move(info, stack_a, stack_b);
		else
			rr_move(info, stack_a, stack_b);
	}
	else if (info[0] == 'p')
		p_move(info, stack_a, stack_b);
}
