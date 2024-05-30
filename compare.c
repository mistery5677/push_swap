#include "push_swap.h"

int	ft_lstsize2(t_stack *lst)
{
	t_stack *temp;
	int		count;

	count = 0;
	temp = lst;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

int compare_last(t_stack **stack)
{       
        int len;
        int end;

        len = ft_lstsize2(*stack);
		printf("len: %d", len);
        end = stack[2]->number;
        return end;
}