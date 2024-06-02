#include "push_swap.h"

void free_stack(t_stack *stack)
{
    t_stack *temp;
    
    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

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

void create_node(t_stack **stack, const char *content)
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

void create_stack(t_stack **stack, int argc, char **argv)
{
    int i;

    i = 1; //Para Linux, devemos de mudar este valor para 0 ... em principio
    while(i < argc)
    {
        create_node(stack, argv[i]);
        i++;
    }
}