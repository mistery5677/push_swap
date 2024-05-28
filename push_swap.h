#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft/libft.h"

typedef struct s_stack
{
	int		    number;
	int 	temp;
	struct s_stack	*next;
}					t_stack;

void free_stack(t_stack *stack);
t_stack	*ft_lstnew2(int content);
void create_stack(t_stack **stack, const char *content);
int compare_last(t_stack **stack);

#endif