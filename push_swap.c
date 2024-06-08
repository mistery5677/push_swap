#include "push_swap.h"

void sort_stack(t_stack *stack_a, t_stack *stack_b)
{
        
}

void push_swap(int argc, char **argv)
{
        t_stack *stack_a;
        t_stack *stack_b;

        stack_a = NULL;
        stack_b = NULL;
        create_stack(&stack_a, argc, argv);
        while(!sort(stack_a))
                sort_stack(stack_a, stack_b);
}