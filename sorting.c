#include "push_swap.h"

void ft_sort3(t_stack **stack_a, t_stack **stack_b)
{
	int i;

	i = 0;
	while (i < 3 && stack_b != NULL )
	{
		move_push(stack_a, stack_b, "pa\n");
		i++;
	}
	while(!sort(*stack_a))
	{
		if(node_number(stack_a, 0) > node_number(stack_a, 1) && node_number(stack_a, 0) > node_number(stack_a, 2))
			move_reverse(stack_a, "ra\n");
		if(node_number(stack_a,0) > node_number(stack_a, 1))
			move_swap(stack_a, "sa\n");
		if(node_number(stack_a, 1) > node_number(stack_a, 2))
			move_rreverse(stack_a, "rra\n");
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{

	while(*stack_a != NULL && stack_a != NULL)
		move_push(stack_b, stack_a, "pb\n");
	ft_sort3(stack_a, stack_b);
	count_moves(*stack_a);
	count_moves(*stack_b);
	find_bf(*stack_a, *stack_b);
	//ft_move(*stack_a, *stack_b);
}