#include "push_swap.h"

//Verify if the list is sorted
int sort(t_stack *stack)
{
	t_stack *tmp_stack;
	t_stack *tmp_head;
	int number;

	number = 0;
	tmp_head = stack;
	while(tmp_head != NULL)
	{
		number = tmp_head->number;
		tmp_stack = tmp_head;
		while(tmp_stack != NULL)
		{
			if(number > tmp_stack->number)
				return 0;
			tmp_stack = tmp_stack->next;
		}
		tmp_head = tmp_head->next;
	}
	return 1;
}

void	move_swap(t_stack **stack)
{
	t_stack *copy;

	copy = *stack;
	copy->temp = node_number(stack, 0);
	copy->number = node_number(stack, 1);
	copy = copy->next;
	copy->number = node_temp(stack, 0);
}

void 	move_reverse(t_stack **stack)
{
	t_stack *copy;
	int first_temp;
	int size;

	size = ft_stacksize(*stack);
	copy = *stack;
	first_temp = copy->number;
	while(size > 1)
	{
		copy->number = copy->next->number;
		copy = copy->next;
		size--;
	}
	copy->number = first_temp;
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