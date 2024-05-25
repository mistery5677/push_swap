#include "push_swap.h"

void create_stack(t_stack **stack, char *content)
{
    int number;
    t_stack *new_node;

    number = ft_atoi((int)ft_lstnew(number));
    if(*stack == NULL)
        *stack = new_node;
    else
    {
        t_stack *current = *stack;
        while(current -> next != NULL)
            current = current->next;
        current->next = new_node;
    }  
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    int i;

    i = 1;
    while(i < argc)
    {
        create_stack(stack_a, argv[i]);
        i++;
    }
    while(stack_a != NULL)
    {
        stack_a = stack_a;
        printf("%d \n", stack_a->number);
    }
}