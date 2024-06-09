#include "push_swap.h"

void ft_sort_stacka(t_stack **stack_a, t_stack **stack_b, int minimum)
{
        t_stack *tmp_stack;
        int distance;

        tmp_stack = *stack_a;
        distance = 0;
        while(tmp_stack->number != minimum)
        {
                distance++;
                tmp_stack = tmp_stack->next;
        }
        if(distance < ft_stacksize(*stack_a))
        {
                while(distance > 0)
                {
                        distance--;
                        move_push(stack_b, stack_a);
                }
                move_reverse(stack_a);
        }
}

void ft_sort_stackb(t_stack **stack_b, t_stack **stack_a, int minimum)
{
        t_stack *tmp_stack;
        int distance;

        tmp_stack = *stack_b;
        distance = 0;
        while(tmp_stack->number != minimum)
        {
                distance++;
                tmp_stack = tmp_stack->next;
        }
        if(distance < ft_stacksize(*stack_b))
        {
                while(distance > 0)
                {
                        distance--;
                        move_push(stack_b, stack_a);
                }
                move_reverse(stack_a);
        }
}

void   first_sort(t_stack **stack_a, t_stack **stack_b)
{
        int minimum;
        int distance;

        distance = 0;
        minimum = lower_number(*stack_a, *stack_a);
        if(minimum == node_number(stack_a, ft_stacksize(*stack_a) - 1))
        {
                minimum = lower_number(*stack_a, *stack_a); //Apenas para aumentar a flag da função
                minimum = find_lower(*stack_a, 2, 1); //Vai encontrar o número 
                distance = ft_distance(*stack_a, minimum);
        }
        while(distance > 0)
        {
                move_push(stack_b, stack_a);
                ft_printf("pb\n");
                distance--;
        }
        move_reverse(stack_a);
        ft_printf("sa\n");
}

void sort_stack(t_stack **stack_a, t_stack **stack_b)
{
        int minimum;
        int found;

        minimum = lower_number(stack_a, stack_b);
        found = find_stack(stack_a, stack_b, minimum);
        if(found == 1)
                ft_sort_stacka(stack_a, stack_b, minimum);
        else if(found == 2)
                ft_sort_stackb(stack_b);
}

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
        if(!sort(stack_a))
        {
                first_sort(&stack_a, &stack_b);
                while(!sort(stack_a))
                        sort_stack(&stack_a, &stack_b);
        }
}