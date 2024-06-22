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

void count_moves(t_stack *stack)
{
    t_stack *tmp_stack;
    int moves;

    print_stack(&stack);
    moves = 0;
    tmp_stack = stack;
    while(tmp_stack != NULL)
    {
        tmp_stack->r_move = moves;
        tmp_stack = tmp_stack->next;
        moves++;
    }
    tmp_stack = stack;
    while(moves > 0)
    {
        tmp_stack->rr_move = moves;
        moves--;
        tmp_stack = tmp_stack->next;
    }
}

void first_bf(t_stack *tmp_stacka, t_stack *tmp_stackb)
{
    while(tmp_stackb != NULL)
    {
        if(tmp_stackb->number < tmp_stacka->number)
        {
            tmp_stacka->move_together = 
            tmp_stacka->bf = tmp_stackb->number;
        }
        tmp_stackb = tmp_stackb->next;
    }
    tmp_stacka = tmp_stacka->next
}

void find_bf(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_stacka;
    t_stack *tmp_stackb;
    int last_nbr;

    last_nbr = tmp_stacka->number;
    tmp_stacka = stack_a;
    tmp_stackb = stack_b;
    first_bf(tmp_stacka, tmp_stack_b);
    tmp_stack_b = stack_b;
    while(tmp_stacka != NULL)
    {
        tmp_stackb = stack_b;
        while(tmp_stackb != NULL)
        {
            if(tmp_stackb->number < tmp_stacka->number && (tmp_stackb->number >= last_nbr))

            tmp_stackb = tmp_stackb->next;
        }
        last_nbr = tmp_stacka->number;
        tmp_stacka = tmp_stacka->next;
    }

}

/* void find_bstopt(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_stacka;
    t_stack *tmp_stackb;

    tmp_stacka = stack_a;
    tmp_stackb = stack_b;
    count_moves(stack_a);
    count_moves(stack_b);
}
 */


/* void sort_to_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_stacka;
    t_stack *tmp_stackb;
    int moves;

    moves = 0;
    tmp_stacka = *stack_a;
    tmp_stackb = *stack_b;
    
} */