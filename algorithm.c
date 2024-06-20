#include "push_swap.h"

int	ft_distance(t_stack *stack, int number)
{
	t_stack	*tmp_stack;
	int		i;

	tmp_stack = stack;
	i = 0;
	while (tmp_stack->number != number && tmp_stack != NULL)
	{
		tmp_stack = tmp_stack->next;
		i++;
	}
	return (i);
}

void count_moves(t_stack *stack_a)
{
    t_stack *tmp_stack;
    int moves;
    int size;

    size = ft_stacksize(stack_a);
    moves = 0;
    tmp_stack = stack_a;
    while(moves < size / 2)
    {
        tmp_stack->moves = moves;
        tmp_stack = tmp_stack->next;
        moves++;
    }
    while(tmp_stack != NULL)
    {
        tmp_stack->moves = moves;
        tmp_stack = tmp_stack->next;
        moves--;
    }
}

void sort_to_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_stacka;
    t_stack *tmp_stackb;
    int moves;

    moves = 0;
    tmp_stacka = *stack_a;
    tmp_stackb = *stack_b;
    
}