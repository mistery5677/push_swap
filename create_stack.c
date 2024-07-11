/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:51:33 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/12 00:56:41 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	create_node(t_stack **stack, const char *content)
{
	int		number;
	t_stack	*new_node;
	t_stack	*current;

	number = ft_atoi(content);
	new_node = ft_lstnew2(number);
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}

int	ft_stacksize(t_stack *stack)
{
	t_stack	*temp;
	int		count;

	count = 0;
	temp = stack;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_stack	*ft_lstnew2(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = content;
	new_node->next = NULL;
	return (new_node);
}

void	create_stack(t_stack **stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		
		create_node(stack, argv[i]);
		i++;
	}
}

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
	free(stack);
}
