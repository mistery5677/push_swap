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

static int move_together(int ra, int rra, int rb, int rrb)
{   
    int rr;
    int rrr;
    int rarrb;
    int rrarb;

    rarrb = ra + rrb;
    rrarb = rra + rb;
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
        //printf("rra %d rrb %d", rra, rrb);
        rra--;
        rrb--;
        rrr++;
    }
    //printf("rr %d rrr %d\n", rr, rrr);
    //ft_printf("rarrb %d rrarb %d rr %d rrr %d ra %d rb %d\n", rarrb, rrarb, rr, rrr, ra, rb);
    if (rarrb < rr + ra + rb && rarrb < rrr + rra + rrb && rarrb < rrarb)
    {
        ft_printf("entrou 1\n");
        return rarrb;
    }
    else if (rrarb < rr + ra + rb && rrarb < rrr + rra + rrb && rrarb < rarrb)
    {
        ft_printf("entrou 2\n");
        return rrarb;
    }
    else if (rr <= rrr)
    {
        ft_printf("entrou 3\n");
        return rr + ra + rb + 1;
    }
    else
    {
        ft_printf("entrou 4\n");   
        return rrr + rra + rrb + 1;
    }
}

static void first_bf(t_stack *tmp_stacka, t_stack *stack_b)
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
    t_stack *lowest_node;
    int last_nbr;

    lowest_node = stack_a;
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
                lowest_node->move_together = 0;
                lowest_node = tmp_stacka;
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

static t_stack *find_best(t_stack *stack_a)
{
    t_stack *tmp_stacka;

    tmp_stacka = stack_a;
    while(tmp_stacka != NULL && tmp_stacka->move_together == 0)
        tmp_stacka = tmp_stacka->next;
    if(tmp_stacka > 0)
        return tmp_stacka;
    else
        return stack_a;

}

static t_stack *target_b (int target, t_stack *stack_b)
{
    t_stack *found;

    found = stack_b;
    while(found->number != target && found !=NULL)
        found = found->next;
    return found;
}

static int what_move(t_stack *stack_a, t_stack *stack_b)
{
    int option;
    int result;

    result = 0;
    option = 0;
    if(stack_a->r_move > stack_b->r_move)
        result = stack_a->r_move - stack_b->r_move;
    else 
        result = stack_b->r_move - stack_a->r_move;
}

void ft_move(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *best_movea;
    t_stack *b_target;

    best_movea =  find_best(stack_a); //Target para o node mais barato
    b_target = (best_movea->bf, stack_b); // Target para o node de b correspondente
    
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

/* 0 1 2 3 4 6 7 8


rrr / rrb / rrb / pp / pa / pa / ra / pa / ra / pa / pa / 3ra  */

/* 10 11 0 1 2 6 7 8

rra / pa / pa / 2 rra / 3 pa / 2 ra = 10*/

/* 0 1 2 6 7 8 10 11

rra / 2pa / 2ra / pa / 2 pa / 2ra = 10*/

//10 11 0 6 7 1 2 8

