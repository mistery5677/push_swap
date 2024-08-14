/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:47:20 by mistery576        #+#    #+#             */
/*   Updated: 2024/08/12 22:19:42 by mistery576       ###   ########.fr       */
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
			if ((argv[i][j] < '0' || argv[i][j] > '9')
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_all(char *info, t_stack *stack_a, t_stack *stack_b)
{
	free(info);
	free_stack(stack_a);
	free_stack(stack_b);
}

static int	check_info(char *info, t_stack *stack_a, t_stack *stack_b)
{
	char	*options[11];
	int		i;

	i = 0;
	options[0] = "ra\n";
	options[1] = "rb\n";
	options[2] = "rr\n";
	options[3] = "pa\n";
	options[4] = "pb\n";
	options[5] = "rra\n";
	options[6] = "rrb\n";
	options[7] = "rrr\n";
	options[8] = "sa\n";
	options[9] = "sb\n";
	options[10] = "ss\n";
	while (i < 11)
	{
		if (ft_strncmp(info, options[i], ft_strlen(options[i])) == 0)
			return (0);
		i++;
	}
	free_all(info, stack_a, stack_b);
	return (1);
}

void	push_swap_bonus(t_stack *stack_a, t_stack *stack_b, int argc,
		char **argv)
{
	char	*info;

	create_stack(&stack_a, argc, argv);
	if (check(stack_a, argv) == 0 && valid_arg(argv) == 0 && argc > 2)
	{
		info = get_next_line(0);
		while (info != NULL)
		{
			if (check_info(info, stack_a, stack_b) == 1)
				return (ft_putstr_fd("Error\n", 2));
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
	push_swap_bonus(stack_a, stack_b, argc, argv);
}
