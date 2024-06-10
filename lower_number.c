#include "push_swap.h"

int first_lower(t_stack *stack)
{
    int minimum;
    t_stack *tmp_stack;

    tmp_stack = stack;
    minimum = tmp_stack->number;
    while(tmp_stack != NULL)
    {
        if(minimum > tmp_stack->number)
            minimum = tmp_stack->number;
        tmp_stack = tmp_stack->next;
    }
    return minimum;
}

/* int find_lower(t_stack *stack, int limit, int safe)
{
    if(stack == NULL)
        return safe;
    t_stack *tmp_stack;
    int minimum;
    int size;

    tmp_stack = stack;
    size = ft_stacksize(tmp_stack);
    minimum = tmp_stack->number;
    while(size - limit >= 0)
    {
        if (minimum > tmp_stack->number)
            minimum = tmp_stack->number;
        tmp_stack = tmp_stack->next;
        limit++;
    }
    return minimum;
}

int lower_number(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_stacka;
    t_stack *tmp_stackb;
    static int flag;
    int minimuma;
    int minimumb;

    tmp_stacka = stack_a;
    tmp_stackb = stack_b;
    if(flag == 0)
    {
        flag++;
        return first_lower(tmp_stacka);
    }
    else 
    {
        flag++;
        minimuma = find_lower(tmp_stacka, flag, tmp_stacka->number);
        minimumb = find_lower(tmp_stackb, 1, minimuma);
        printf("flag %d minimumb %d minimuma %d\n", flag, minimuma, minimumb);
        if(minimuma <= minimumb && flag < ft_stacksize(stack_a))
            return minimuma;
        return minimumb;
    }
    return 0;
} */

int lower_number(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp_stack_a;
    int minimuma;
    int last;
    
    last = node_number(&stack_a, ft_stacksize(stack_a) - 1);
    minimuma = stack_a->number;
    tmp_stack_a = stack_a;
    if(stack_b == NULL)
    {
        while(tmp_stack_a != NULL)
        {
            if(minimuma > last && minimuma > tmp_stack_a->number)
                minimuma = tmp_stack_a->number;
            tmp_stack_a = tmp_stack_a->next;
        }
        return minimuma;
    }
    t_stack *tmp_stack_b;
    int minimumb;

    tmp_stack_b = stack_b;
    minimumb = stack_b->number;
    while(tmp_stack_a != NULL)
    {
        if(tmp_stack_a->number > last && minimuma > tmp_stack_a->number)
        {
            printf("antes %d last %d\n", minimuma, last);
            minimuma = tmp_stack_a->number;
            printf("depois %d\n", minimuma);
        }
        tmp_stack_a = tmp_stack_a->next;
    }
    while(tmp_stack_b != NULL)
    {
        if(minimumb > tmp_stack_b->number)
            minimumb = tmp_stack_b->number;
        tmp_stack_b = tmp_stack_b->next;
    }
    printf("minimuma %d minimumb %d\n", minimuma, minimumb);
    if(minimumb > minimuma && minimuma > last)
        return minimuma;
    return minimumb;
}

int ft_distance(t_stack *stack, int number)
{
    t_stack *tmp_stack;
    int i;
    int stack_size;

    tmp_stack = stack;
    stack_size = ft_stacksize(tmp_stack);
    i = 0;
    while(tmp_stack->number != number)
    {
        tmp_stack = tmp_stack->next;
        i++;
    }
    if(i > stack_size / 2)
    {
        i = -1;
        while(tmp_stack != NULL)
        {
            tmp_stack = tmp_stack->next;
            i++;
        }
    }
    return i;
}

int find_stack(t_stack *stack_a, t_stack *stack_b, int minimum)
{
    t_stack *tmp_stacka;
    t_stack *tmp_stackb;

    tmp_stacka = stack_a;
    tmp_stackb = stack_b;
    while(tmp_stacka != NULL)
    {
        if(tmp_stacka->number == minimum)
            return 1;
        tmp_stacka = tmp_stacka->next;
    }
    while(tmp_stackb != NULL)
    {
        if(tmp_stackb->number == minimum)
            return 2;
        tmp_stackb = tmp_stackb->next;
    }
    return 0;
}
