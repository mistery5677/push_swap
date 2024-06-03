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
    t_stack *current2 = stack_a;
    while (current != NULL)
    {
        ft_printf("%d \n", current->number);
        current = current->next;
    }
    free_stack(stack_a);
} */

//Testar Sa
/* int main(int argc, char **argv)
{
    t_stack *head_a;
    t_stack *stack_a;

    head_a = NULL;
    stack_a = head_a;
    create_stack(&stack_a, argc, argv);
    t_stack *current = stack_a;
    while (current != NULL)
    {
        ft_printf("%d \n", current->number);
        current = current->next;
    }
    current = stack_a;
    move_swap(&current);
    ft_printf("depois\n");
    while(current != NULL)
    {
        ft_printf("%d \n", current->number);
        current = current->next;
    }
    current = stack_a;
    move_swap(&current);
    ft_printf("depois\n");
    while(current != NULL)
    {
        ft_printf("%d \n", current->number);
        current = current->next;
    }
    free_stack(stack_a);
} */

//Tester ra e rra
/* int main(int argc, char **argv)
{
    t_stack *head_a;
    t_stack *stack_a;

    head_a = NULL;
    stack_a = head_a;
    create_stack(&stack_a, argc, argv);
    t_stack *current = stack_a;
    while (current != NULL)
    {
        ft_printf("%d \n", current->number);
        current = current->next;
    }
    current = stack_a;
    move_reverse(&current);
    ft_printf("depois\n");
    while(current != NULL)
    {
        ft_printf("%d \n", current->number);
        current = current->next;
    }
    current = stack_a;
    move_rreverse(&current);
    ft_printf("depois\n");
    while(current != NULL)
    {
        ft_printf("%d \n", current->number);
        current = current->next;
    }
    free_stack(stack_a);
} */