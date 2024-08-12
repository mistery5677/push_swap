/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:58:37 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/09 12:39:22 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort(t_stack *stack)
{
	t_stack	*tmp_stack;
	t_stack	*tmp_head;
	int		number;

	number = 0;
	tmp_head = stack;
	while (tmp_head != NULL)
	{
		number = tmp_head->number;
		tmp_stack = tmp_head;
		while (tmp_stack != NULL)
		{
			if (number > tmp_stack->number)
				return (0);
			tmp_stack = tmp_stack->next;
		}
		tmp_head = tmp_head->next;
	}
	return (1);
}

void	move_swap(t_stack **stack, char *move)
{
	t_stack	*copy;

	copy = *stack;
	copy->temp = node_number(stack, 0);
	copy->number = node_number(stack, 1);
	copy = copy->next;
	copy->number = node_temp(stack, 0);
	ft_printf("%s", move);
}

void	move_reverse(t_stack **stack, char *move)
{
	t_stack	*copy;
	int		first_temp;
	int		size;

	size = ft_stacksize(*stack);
	copy = *stack;
	first_temp = copy->number;
	while (size > 1)
	{
		copy->number = copy->next->number;
		copy = copy->next;
		size--;
	}
	copy->number = first_temp;
	ft_printf("%s", move);
}

void	move_rreverse(t_stack **stack, char *move)
{
	t_stack	*copy;
	int		i;

	i = 0;
	copy = *stack;
	copy->temp = copy->number;
	copy->number = node_number(stack, ft_stacksize(*stack) - 1);
	copy = copy->next;
	while (i < ft_stacksize(*stack) - 1)
	{
		copy->temp = copy->number;
		copy->number = node_temp(stack, i);
		copy = copy->next;
		i++;
	}
	ft_printf("%s", move);
}

void	move_push(t_stack **dest, t_stack **src, char *move)
{
	t_stack	*new_node;
	t_stack	*tmp_src;

	if (!src || !(*src))
		return ;
	new_node = ft_lstnew2((*src)->number);
	new_node->next = *dest;
	*dest = new_node;
	tmp_src = *src;
	*src = (*src)->next;
	ft_printf("%s", move);
	free(tmp_src);
}
