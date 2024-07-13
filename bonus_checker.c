/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:47:20 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/13 02:53:25 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

static int	valid_arg(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	bonus_checker(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	char	*info;

	create_stack(&stack_a, argc, argv);
	if (check(stack_a, argv) == 0 && valid_arg(argv) == 0 && argc > 2)
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
