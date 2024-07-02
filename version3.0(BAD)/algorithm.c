#include "push_swap.h"

int lowest_number(t_stack *stack)
{
        t_stack *tmp_stack;
        int lowest;

        tmp_stack = stack;
        lowest = tmp_stack->number;
        while(tmp_stack != NULL)
        {
                if(tmp_stack->number < lowest)
                        lowest = tmp_stack->number;
                tmp_stack = tmp_stack->next;
        }
        return lowest;
}

//Vai procurar na 'stack', pelo numero mais alto, comparativamente com o 'number'
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
        if (flag == 0)
                return number;
        return higher;
}

//Descobre quantos movimentos para movimentar para o topo da lista b
int worth_up(t_stack *stack_a, t_stack *stack_b)
{
        int movements;
        int near_higher;
        int number_b;

        number_b = node_number(&stack_b, 0);
        near_higher = ft_near_higher(stack_a, number_b);
        ft_printf("near_higher %d ", near_higher);
        if(near_higher == number_b)
                movements = ft_distance(stack_a, lowest_number(stack_a));
        else
                movements = ft_distance(stack_a, near_higher);
        return movements; 
}

int biggest_number(t_stack *stack)
{
        t_stack *tmp_stack;
        int biggest;

        tmp_stack = stack;
        biggest = tmp_stack->number;
        while(tmp_stack != NULL)
        {
                if(tmp_stack->number > biggest)
                        biggest = tmp_stack->number;
                tmp_stack = tmp_stack->next;
        }
        return biggest;
}

//Vai procurar na 'stack', pelo numero mais baixo, comparativamente com o 'number'
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
        if (flag == 0)
                return number;
        return lower;
}

//Descobre quantos movimentos para movimentar para o fim da lista b
int worth_down(t_stack *stack_a, t_stack *stack_b)
{
        int movements;
        int near_lower;
        int number_b;

        number_b = node_number(&stack_b, ft_stacksize(stack_b) - 1);
        near_lower = ft_near_lower(stack_a, number_b);
        ft_printf("near_higher %d ", near_lower);
        if(near_lower == number_b)
                movements = ft_distance(stack_a, biggest_number(stack_a));
        else
                movements = ft_distance(stack_a, near_lower);
        return movements; 
}

