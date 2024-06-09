#include "push_swap.h"

void first_sort(t_stack *stack_a, t_stack *stack_b)
{
        int minimum;
        int distance;

        distance = 0;
        minimum = lower_number(stack_a, stack_a);
        if(minimum == node_number(&stack_a, ft_stacksize(stack_a) - 1))
        {
                minimum = lower_number(stack_a, stack_a); //Apenas para aumentar a flag da função
                minimum = find_lower(stack_a, 2, 1); //Vai encontrar o número 
                distance = ft_distance(stack_a, minimum);
        }
        while(distance > 0)
        {
                move_push(&stack_b, &stack_a);
                ft_printf("pb\n");
                distance--;
        }
        move_reverse(&stack_a);
        ft_printf("sa\n");
}

void sort_stack(t_stack *stack_a, t_stack *stack_b)
{
        int minimum;
        int found;

        minimum = lower_number(stack_a, stack_b);
        found = find_stack(stack_a, stack_b, minimum);
        (void)found;
}

void push_swap(int argc, char **argv)
{
        t_stack *stack_a;
        t_stack *stack_b;

        stack_a = NULL;
        stack_b = NULL;
        (void)stack_b;
        create_stack(&stack_a, argc, argv);
}