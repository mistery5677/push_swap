#include "push_swap.h"

/* 
//Este teste server para imprimir a lista com os dados que recebeu
int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    int i;

    i = 1;
    while(i < argc)
    {
        create_stack(&stack_a, argv[i]);
        i++;
    }
    t_stack *current = stack_a;
    while (current != NULL)
    {
        ft_printf("%d \n", current->number);
        current = current->next;
    }
    free_stack(stack_a);
} */

int main(int argc, char **argv)
{
    t_stack *head_a;
    t_stack *stack_a;
    
    head_a = NULL;
    stack_a = head_a;
    create_stack(&stack_a, argc, argv);
    int end = compare_node(&stack_a, 1);
    printf("end: %d", end);
    free_stack(stack_a);
}