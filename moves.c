#include "push_swap.h"

void	move_swap(t_stack **stack)
{
	t_stack *copy;

	copy = *stack;
	copy->temp = node_number(stack, 0);
	copy->number = node_number(stack, 1);
	copy = copy->next;
	copy->number = node_temp(stack, 0);
	printf("number %d\n", copy->number);
}

void 	move_reverse(t_stack **stack)
{
	t_stack *copy;
	int i;

	i = 0;
	copy = *stack;
	copy->temp = copy->number;
	while(i <= ft_stacksize(copy))
	{
		copy->number = node_number(stack, i + 1);
		copy = copy->next;
		i++;
	}
	copy->number = node_temp(stack, 0);
}

void	move_rreverse(t_stack **stack)
{
	t_stack *copy;
	int i;

	i = 0;
	copy = *stack;
	copy->temp = copy->number;
	copy->number = node_number(stack, ft_stacksize(*stack) - 1); //Colocamos '-1' para não acedermos ao NULL 
	copy = copy->next;
	while(i < ft_stacksize(*stack) - 1)
	{
		copy->temp = copy->number;
		copy->number = node_temp(stack, i);
		copy = copy->next;
		i++;
	}
}

void	move_push(t_stack **dest, t_stack **src)
{

}

/* 4 2
5 4
6 5
2 6 */