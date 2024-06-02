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