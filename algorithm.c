#include "push_swap.h"

static int highest_number(t_stack *stack)
{
    t_stack *tmp_stack;
    int highest;

    tmp_stack = stack;
    highest = stack->number;
    while(tmp_stack != NULL)
    {
        if(tmp_stack->number > highest)
            highest = tmp_stack->number;
        tmp_stack = tmp_stack->next;
    }
    return highest;
}

static t_stack *find_best_utils(t_stack *stack_a, t_stack *stack_b)
{
    stack_a->bf = highest_number(stack_b);
    stack_a->move_together = move_together(stack_a->r_move, stack_a->rr_move, stack_b->r_move, stack_b->rr_move);
    return stack_a;
}

static t_stack *find_best(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_stacka;

    tmp_stacka = stack_a;
    while(tmp_stacka != NULL && tmp_stacka->move_together == 0)
        tmp_stacka = tmp_stacka->next;
    if(tmp_stacka != NULL && tmp_stacka->move_together > 0)
    {
        return tmp_stacka;
    }
    else
        return find_best_utils(stack_a,stack_b);
    //printf("tmp_stacka number %d", stack_a->number);
}

static t_stack *target_b (int target, t_stack *stack_b)
{
    t_stack *found;

    found = stack_b;
    while(found->number != target && found != NULL)
        found = found->next;
    return found;
}

static int many_rr(t_stack  *stack_a, t_stack *stack_b)
{
    int ra;
    int rb;
    int rr;

    rr = 0;
    ra = stack_a->r_move;
    rb = stack_b->r_move;
    //printf("stack_b number %d\n", stack_b->number);
    while(ra > 0 && rb > 0)
    {
        ra--;
        rb--;
        rr++;
    }
    return rr + ra + rb;
}

static int what_move(t_stack *stack_a, t_stack *stack_b)
{
    if(stack_a->move_together == (stack_a->r_move + stack_b->rr_move) + 1)
        return 1;
    else if(stack_a->move_together == (stack_a->rr_move + stack_b->r_move) + 1)
        return 2;
    else if(stack_a->move_together == (many_rr(stack_a, stack_b))+ 1)
        return 3;
    else
        return 4;
}

static void option_1(t_stack **stack_a, t_stack **stack_b, int ra, int rrb)
{
    while(ra > 0)
    {
        move_reverse(stack_a, "ra\n");
        ra--;
    }
    while(rrb > 0)
    {
        move_rreverse(stack_b, "rrb\n");
        rrb--;
    }
    move_push(stack_a, stack_b, "pa\n");
}

static void option_2(t_stack **stack_a, t_stack **stack_b, int rra, int rb)
{
    while(rra > 0)
    {
        move_rreverse(stack_a, "rra\n");
        rra--;
    }
    while(rb > 0)
    {
        move_reverse(stack_b, "rb\n");
        rb--;
    }
    move_push(stack_a, stack_b, "pa\n");
}

static void option_3(t_stack **stack_a, t_stack **stack_b, int ra, int rb)
{
    while(ra > 0 && rb > 0)
    {
        move_reverse(stack_a, "r");
        move_reverse(stack_b, "r\n");
        ra--;
        rb--;
    }
    while(ra > 0)
    {
        move_reverse(stack_a, "ra\n");
        ra--;
    }
    while(rb > 0)
    {
        move_reverse(stack_b, "rb\n");
        rb--;
    }
    move_push(stack_a, stack_b, "pa\n");
}

static void option_4(t_stack **stack_a, t_stack **stack_b, int rra, int rrb)
{
    //printf("rra %d rrb %d\n", rra, rrb);
    //printf("stack a number %d stack b number %d\n", stack_a->number, stack_b->number);
    while(rra > 0 && rrb > 0)
    {
        move_rreverse(stack_a, "rr");
        move_rreverse(stack_b, "r\n");
        rra--;
        rrb--;
    }
    while(rra > 0)
    {
        move_rreverse(stack_a, "rra\n");
        rra--;
    }
    while(rrb > 0)
    {
        move_rreverse(stack_b, "rrb\n");
        rrb--;
    }
    move_push(stack_a, stack_b, "pa\n");
}

static void clean_info(t_stack *stack_a)
{
    t_stack *tmp_stacka;

    tmp_stacka = stack_a;
    while(tmp_stacka != NULL)
    {
        tmp_stacka->bf = 0;
        tmp_stacka->move_together = 0;
        tmp_stacka = tmp_stacka->next;
    }
}

void ft_move(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *best_movea;
    t_stack *b_target;
    int option;

/*     print_all(stack_a);
    printf("stack b\n");
    print_all(stack_b); */
    best_movea =  find_best(*stack_a, *stack_b); //Target para o node mais barato
    b_target = target_b(best_movea->bf, *stack_b); // Target para o node de b correspondente     
/*     print_all(stack_a);
    printf("stack b \n");
    print_all(stack_b); */
/*     print_all(stack_a);
    printf("stack b\n");
    print_all(stack_b); */
    //printf("b nbr %d a number %d\n", b_target->number, best_movea->number);
    //printf("best_movea number %d\n",(*stack_a)->number);
    option = what_move(best_movea, b_target);
    //printf("option %d\n", option);
    //printf("(ft_move) option %d\n", option);
    if(option == 1)
        option_1(stack_a, stack_b, best_movea->r_move, b_target->rr_move);
    else if(option == 2)
        option_2(stack_a, stack_b, best_movea->rr_move, b_target->r_move);
    else if(option == 3)
        option_3(stack_a, stack_b, best_movea->r_move, b_target->r_move);
    else if(option == 4)
        option_4(stack_a, stack_b, best_movea->rr_move, b_target->rr_move);
    //printf("(ft_move) Depois dos moves\n");
    //print_all(stack_a);
    clean_info(*stack_a);
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

