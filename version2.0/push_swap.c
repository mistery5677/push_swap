/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:30:26 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/11 17:41:10 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stacka(t_stack **stack_a, t_stack **stack_b, int minimum, int midium)
{
	t_stack	*tmp_stack;
	int		distance;
	
	printf("minimum %d\n", minimum);
	tmp_stack = *stack_a;
	distance = 0;
	while (tmp_stack->number != minimum)
	{
		distance++;
		tmp_stack = tmp_stack->next;
	}
	while (distance > 0)
	{
		distance--;
		move_push(stack_b, stack_a);
		ft_printf("pb\n");
		if((*stack_b)->number >= midium)
		{
			move_reverse(stack_b);	
			ft_printf("rb\n");
		}
		else if((*stack_b)->next != NULL && (*stack_b)->number > (*stack_b)->next->number)
		{
			move_swap(stack_b);
			ft_printf("sb\n");			
		}	
	}
	distance = ft_distance(*stack_a, minimum);
	move_reverse(stack_a);
	ft_printf("ra\n");
}

void	ft_sort_stackb(t_stack **stack_b, t_stack **stack_a, int minimum)
{
	t_stack	*tmp_stack;
	int		distance;
	int		size;

	size = ft_stacksize(*stack_b);
	tmp_stack = *stack_b;
	distance = 0;
	while (tmp_stack->number != minimum)
	{
		distance++;
		tmp_stack = tmp_stack->next;
	}
	if (distance > size / 2)
	{
		distance = size - distance;
		while (distance > 0)
		{
			distance--;
			move_rreverse(stack_b);
			ft_printf("rrb\n");
		}
		move_push(stack_a, stack_b);
		move_reverse(stack_a);
		ft_printf("pa\nra\n");
	}
	else
	{
		while (distance > 0)
		{
			distance--;
			move_reverse(stack_b);
			ft_printf("rb\n");
		}
		move_push(stack_a, stack_b);
		move_reverse(stack_a);
		ft_printf("pa\nra\n");
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int midium)
{
	int	minimum;
	int	found;
	static int flag;

	minimum = lower_number(*stack_a, *stack_b);
	if (flag == 0)
	{
		flag ++;
		minimum = first_lower(*stack_a);
	}
	found = find_stack(*stack_a, *stack_b, minimum);
	if (found == 1)
		ft_sort_stacka(stack_a, stack_b, minimum, midium);
	else if (found == 2)
		ft_sort_stackb(stack_b, stack_a, minimum);
}

static int ft_midium(t_stack *stack)
{
	t_stack *tmp_stack;
	int midium;

	midium = 0;
	tmp_stack = stack;
	while(tmp_stack != NULL)
	{
		midium = midium + tmp_stack->number;
		tmp_stack = tmp_stack->next;
	}
	midium = midium / ft_stacksize(stack);
	return midium;
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int midium;

	midium = ft_midium(stack_a); 
	if (!sort(stack_a))
	{
		while (!sort(stack_a) || stack_b != NULL)
			sort_stack(&stack_a, &stack_b, midium);
	}
	free_stack(stack_a);
}

/* 4
3
2
5
1

pb pb ra pa ra pa ra ra */