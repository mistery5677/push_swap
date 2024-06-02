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

int node_number(t_stack **stack, int n2)
{       
        int nbr2;
		t_stack *copy;
		int i;	

		i = 0;
		copy = *stack;
		if(copy == NULL)	
			return 0;
		nbr2 = 0;
		while(i < n2)
		{
			copy = copy->next;
			i++;
		}
		nbr2 = copy->number;
        return nbr2;
}

int node_temp(t_stack **stack, int n2)
{       
        int nbr2;
		t_stack *copy;
		int i;

		i = 0;
		copy = *stack;
		if(copy == NULL)	
			return 0;
		nbr2 = 0;
		while(i < n2)
		{
			copy = copy->next;
			i++;
		}
		nbr2 = copy->temp;
        return nbr2;
}