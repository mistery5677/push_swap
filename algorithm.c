/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 15:09:08 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/05 16:07:13 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_best(t_stack *stack_a)
{
	t_stack	*tmp_stacka;

	tmp_stacka = stack_a;
	while (tmp_stacka != NULL && tmp_stacka->move_together == 0)
		tmp_stacka = tmp_stacka->next;
	return (tmp_stacka);
}

static t_stack	*target_b(int target, t_stack *stack_b)
{
	t_stack	*found;

	found = stack_b;
	while (found->number != target && found != NULL)
		found = found->next;
	return (found);
}

static int	what_move(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->move_together == (stack_a->r_move + stack_b->rr_move) + 1)
		return (1);
	else if (stack_a->move_together == (stack_a->rr_move + stack_b->r_move) + 1)
		return (2);
	else if (stack_a->move_together == (many_rr(stack_a, stack_b)) + 1)
		return (3);
	else
		return (4);
}

static void	clean_info(t_stack *stack_a)
{
	t_stack	*tmp_stacka;

	tmp_stacka = stack_a;
	while (tmp_stacka != NULL)
	{
		tmp_stacka->bf = 0;
		tmp_stacka->move_together = 0;
		tmp_stacka = tmp_stacka->next;
	}
}

void	ft_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*best_movea;
	t_stack	*b_target;
	int		option;

	best_movea = find_best(*stack_a);
	b_target = target_b(best_movea->bf, *stack_b);
	option = what_move(best_movea, b_target);
	if (option == 1)
		option_1(stack_a, stack_b, best_movea->r_move, b_target->rr_move);
	else if (option == 2)
		option_2(stack_a, stack_b, best_movea->rr_move, b_target->r_move);
	else if (option == 3)
		option_3(stack_a, stack_b, best_movea->r_move, b_target->r_move);
	else if (option == 4)
		option_4(stack_a, stack_b, best_movea->rr_move, b_target->rr_move);
	clean_info(*stack_a);
}
