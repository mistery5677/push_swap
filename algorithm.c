#include "push_swap.h"

int ft_near_lower(t_stack *stack, int number)
{
        t_stack *tmp_stack;
        int lower;
        int flag;

        flag = 0;
        tmp_stack = stack;
        lower = number;
        while(tmp_stack != NULL)
        {
                if(tmp_stack->number < lower && flag == 0)
                {
                        flag++;
                        lower = tmp_stack->number;
                }
                else if(tmp_stack->number < number && tmp_stack->number > lower)
                        lower = tmp_stack->number;
                tmp_stack = tmp_stack->next;
        }
        return lower;
}

int ft_near_higher(t_stack *stack, int number)
{
        t_stack *tmp_stack;
        int higher;
        int flag;

        flag = 0;
        tmp_stack = stack;
        higher = number;
        while(tmp_stack != NULL)
        {
                if(tmp_stack->number > higher && flag == 0)
                {
                        flag++;
                        higher = tmp_stack->number;
                }
                else if(tmp_stack->number > number && tmp_stack->number < higher)
                        higher = tmp_stack->number;
                tmp_stack = tmp_stack->next;
        }
        return higher;
}
