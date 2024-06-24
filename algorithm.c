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

int move_together(int ra, int rra, int rb, int rrb)
{   
    int rr;
    int rrr;
    int move_all;

    move_all = 
    rr = 0;
    rrr = 0;
    while(ra > 0 && rb > 0)
    {
        ra--;
        rb--;
        rr++;
    }
    while (rra > 0 && rrb > 0)
    {
        printf("rra %d rrb %d", rra, rrb);
        rra--;
        rrb--;
        rrr++;
    }
    printf("rr %d rrr %d\n", rr, rrr);
    if (rr <= rrr)
        return rr + ra + rb;
    else
        return rrr + rra + rrb;
}

void first_bf(t_stack *tmp_stacka, t_stack *stack_b)
{
    t_stack *tmp_stackb;

    tmp_stackb = stack_b;
    while(tmp_stackb != NULL)
    {
        if(tmp_stackb->number < tmp_stacka->number)
        {
            tmp_stacka->move_together = move_together(tmp_stacka->r_move, tmp_stacka->rr_move, tmp_stackb->r_move, tmp_stackb->rr_move);
            tmp_stacka->bf = tmp_stackb->number;
        }
        tmp_stackb = tmp_stackb->next;
    }
}

void find_bf(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_stacka;
    t_stack *tmp_stackb;
    int last_nbr;

    tmp_stacka = stack_a;
    tmp_stackb = stack_b;
    last_nbr = tmp_stacka->number;
    first_bf(tmp_stacka, stack_b);
    tmp_stacka = tmp_stacka->next;
    while(tmp_stacka != NULL)
    {
        tmp_stackb = stack_b;
        while(tmp_stackb != NULL)
        {
            //printf("number_b %d     number_a %d     //      last nbr %d  number_b %d    //      move_toghether_a %d     move_together %d\n", tmp_stackb->number, tmp_stacka->number, last_nbr, tmp_stackb->number, tmp_stacka->move_together, move_together(tmp_stacka->r_move, tmp_stacka->rr_move, tmp_stackb->r_move, tmp_stackb->rr_move));
            if(tmp_stackb->number < tmp_stacka->number && tmp_stackb->number >= last_nbr && (stack_a->move_together == 0 || stack_a->move_together > move_together(tmp_stacka->r_move, tmp_stacka->rr_move, tmp_stackb->r_move, tmp_stackb->rr_move)))
            {
                tmp_stacka->move_together = move_together(tmp_stacka->r_move, tmp_stacka->rr_move, tmp_stackb->r_move, tmp_stackb->rr_move);
                //printf("stack_a move %d tmp_stacka move %d\n", stack_a->move_together, tmp_stacka->move_together);
                tmp_stacka->bf = tmp_stackb->number;
            }
            tmp_stackb = tmp_stackb->next;
        }
        last_nbr = tmp_stacka->number;
        tmp_stacka = tmp_stacka->next;
    }

}

void ft_move(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_stacka;
    t_stack *tmp_stackb;
    // parei aqui ... fazer os movimentos e saber qual o mais eficiente na stack_a para fazer

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