#include "push_swap.h"

int	ft_lstsize2(t_stack *lst)
{
	t_stack *temp;
	int		count;

	count = 0;
	temp = (t_stack *)lst;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int compare_last(t_stack **stack)
{       
        int start;
        int len;
        int end;

        len = ft_lstsize2(&stack);
        start = stack[0]->number;
        end = stack[len]->number;
        return end;
}