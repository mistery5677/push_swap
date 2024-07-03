#include "push_swap.h"

void print_stack(t_stack **stack)
{
    t_stack *temp_stack;

    temp_stack = *stack;
    while (temp_stack != NULL)
    {
        ft_printf("%d \n", temp_stack->number);
        temp_stack = temp_stack->next;
    }
}

void print_all(t_stack **stack_a)
{
    t_stack *tmp_stack;

    tmp_stack = *stack_a;
    while(tmp_stack != NULL)
    {
        printf("number %d   r_moves %d      rr_moves %d     bf %d       move_together %d\n", tmp_stack->number, tmp_stack->r_move, tmp_stack->rr_move, tmp_stack->bf, tmp_stack->move_together);
        tmp_stack = tmp_stack->next;
    }
}
//Este teste serve para imprimir a lista com os dados que recebeu
/* int main(int argc, char **argv)
{
    t_stack *head_a = NULL;
    create_stack(&head_a, argc, argv);
    t_stack *stack_a = head_a;
    while (stack_a != NULL)
    {
        ft_printf("%d \n", stack_a->number);
        stack_a = stack_a->next;
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

//Testa o push
/* int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    create_stack(&stack_a, argc, argv);
    print_stack(&stack_a);
    
    move_reverse(&stack_a);
    printf("depois \n");
    print_stack(&stack_a);
    
    move_rreverse(&stack_a);
    printf("depois \n");
    print_stack(&stack_a);

    move_push(&stack_b, &stack_a);
    printf("stack_a \n");
    print_stack(&stack_a);
    printf("stack_b \n");
    printf("%d\n", stack_b->number);

    move_push(&stack_b, &stack_a);
    printf("stack_a \n");
    print_stack(&stack_a);
    printf("stack_b \n");
    print_stack(&stack_b);

    move_push(&stack_a, &stack_b);
    printf("stack_a \n");
    print_stack(&stack_a);
    printf("stack_b \n");
    print_stack(&stack_b);
    free_stack(stack_a);
    // free(stack_b);
} */

//Test sort function
/* int main(int argc, char **argv)
{
    t_stack *stack_a;

    stack_a = NULL;
    create_stack(&stack_a, argc, argv);
    if(!sort(stack_a))
        printf("KO\n");
    else if (sort(stack_a))
        printf("OK\n");
    free_stack(stack_a);
} */

//Test minimum number
/* int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int minimum;

    stack_b = NULL;
    stack_a = NULL;
    create_stack(&stack_a, argc, argv);
    minimum = lower_number(stack_a, stack_b);
    printf("O valor mais baixo é %d\n", minimum);

    minimum = lower_number(stack_a, stack_b);
    printf("O valor mais baixo é %d\n", minimum);

    minimum = lower_number(stack_a, stack_b);
    printf("O valor mais baixo é %d\n", minimum);
} */

/* int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    create_stack(&stack_a, argc, argv);
    while(!sort(stack_a))
    {
        sort_stack(stack_a, stack_b)
    }
} */

//Testar o First sort (3 2 1)
/* int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    create_stack(&stack_a, argc, argv);
    //print_stack(&stack_a);
    first_sort(&stack_a, &stack_b);
    print_stack(&stack_b);
    printf("\nstacka\n");
    print_stack(&stack_a);
} */

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    stack_a = NULL;
    stack_b = NULL;
    create_stack(&stack_a, argc, argv);
    push_swap(stack_a, stack_b);
}