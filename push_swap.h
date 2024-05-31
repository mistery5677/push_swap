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
void create_node(t_stack **stack, const char *content);
void create_stack(t_stack **stack, int argc, char **argv);

int compare_node(t_stack **stack, int n2);

#endif