#include "push_swap.h"

//Verify if the list is sorted
int sort(t_stack *stack)
{
	t_stack *tmp_stack;
	t_stack *tmp_head;
	int number;

	number = 0;
	tmp_head = stack;
	tmp_stack = stack;
	while(tmp_head->next != NULL)
	{
		number = tmp_head->number;
		while(tmp_stack != NULL)
		{
			printf("number %d\n stack_number %d\n", number, tmp_stack->number);
			if(number > tmp_stack->number)
			{
				printf("entrou\n");
				return 1;
			}
			tmp_stack = tmp_stack->next;
		}
		tmp_head = tmp_head->next;
		printf("number %d\n stack_number %d\n", number, tmp_head->number);
	}
	return 0;
}

void	move_swap(t_stack **stack)
{
	t_stack *copy;

	copy = *stack;
	copy->temp = node_number(stack, 0);
	copy->number = node_number(stack, 1);
	copy = copy->next;
	copy->number = node_temp(stack, 0);
	printf("number %d\n", copy->number);
}

void 	move_reverse(t_stack **stack)
{
	t_stack *copy;
	int i;

	i = 0;
	copy = *stack;
	copy->temp = copy->number;
	while(i <= ft_stacksize(copy))
	{
		copy->number = node_number(stack, i + 1);
		copy = copy->next;
		i++;
	}
	copy->number = node_temp(stack, 0);
}

void	move_rreverse(t_stack **stack)
{
	t_stack *copy;
	int i;

	i = 0;
	copy = *stack;
	copy->temp = copy->number;
	copy->number = node_number(stack, ft_stacksize(*stack) - 1); //Colocamos '-1' para não acedermos ao NULL 
	copy = copy->next;
	while(i < ft_stacksize(*stack) - 1)
	{
		copy->temp = copy->number;
		copy->number = node_temp(stack, i);
		copy = copy->next;
		i++;
	}
}

void move_push(t_stack **dest, t_stack **src)
{
    t_stack *new_node;
    t_stack *tmp_src;

    if (!src || !(*src))
		return ;
    new_node = ft_lstnew2((*src)->number); //Vou criar um novo node, para juntar à lista
    new_node->next = *dest; //Vou  estar a dar a igual o "next node", ao node inicial de dest
    *dest = new_node;
    
	//Limpa o novo node
	tmp_src = *src;
    *src = (*src)->next;
    free(tmp_src);
}