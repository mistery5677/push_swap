/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:51:33 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/12 02:40:53 by mistery576       ###   ########.fr       */
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

static void test1(char *str, t_stack **stack_a)
{
	char *tmp;
	int i;
	int x;

	tmp = NULL;
	i = 0;
	x = i;
	while(str[i])
	{
		if((str[i] >= 9 && str[i] <= 13) || str[i] == ' ' || str[i + 1] == 0)
		{
			tmp = ft_substr(str, x, i);
			x = i + 1;
			create_node(stack_a, tmp);
			free(tmp);
		}
		i++;
	}
}

static int test2(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
			return 1;
		i++;
	}
	return 0;
}

void	create_stack(t_stack **stack, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if(test2(argv[i]) == 1)	
			test1(argv[i], stack);
		else
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
