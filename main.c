#include "push_swap.h"

t_stack *create_stack(int argc, char **argv)
{
    t_stack *stack_a;
    int i;

    i = 0;
    while(argv[i])
    {
        stack_a = malloc(sizeof(t_stack));
        stack_a->number = argv[i];
        i++;
    }

    return stack_a;
}

int main(int argc, char **argv)
{
    t_stack *stack_a = create_stack(argc, argv);
    printf("%d\n", stack_a);
}