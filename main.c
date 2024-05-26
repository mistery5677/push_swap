#include "push_swap.h"

t_stack	*ft_lstnew2(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = content;
	new_node->next = NULL;
	return (new_node);
}


void create_stack(t_stack **stack, char *content)
{
    int number;
    t_stack *new_node;

    number = ft_atoi(content);
    new_node = ft_lstnew2(number);
    if(*stack == NULL)
        *stack = new_node;
    else
    {
        t_stack *current = *stack;
        while(current->next != NULL)
            current = current->next;
        current->next = new_node;
    }  
}

int main(int argc, char **argv)
{
    t_stack *stack_a = NULL;
    int i;

    i = 0;
    while(i < argc)
    {
        create_stack(&stack_a, argv[i]);
        i++;
    }
    while(stack_a != NULL)
    {
        stack_a = stack_a->next;
        printf("entrou \n");
            printf("%d \n", stack_a->number);
    }
}