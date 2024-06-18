#include "push_swap.h"

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
        movements = ft_distance(stack_a, near_higher);
        return movements; 
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
        movements = ft_distance(stack_a, near_lower);
        printf("moves %d\n", movements);
        return movements; 
}

