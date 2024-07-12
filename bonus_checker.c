/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelcosta <miguelcosta@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:47:20 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/12 15:05:12 by miguelcosta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	bonus_checker(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	char	*info;

	create_stack(&stack_a, argc, argv);
	if (check(stack_a, argv) == 0 && argc > 2)
	{
		info = get_next_line(0);
		while (info != NULL)
		{
			verify_info(info, &stack_a, &stack_b);
			free(info);
			info = get_next_line(0);
		}
		if (sort(stack_a) && stack_a != NULL && ft_stacksize(stack_b) == 0)
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
	}
	else
		ft_putstr_fd("Error\n", 2);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	bonus_checker(stack_a, stack_b, argc, argv);
}
