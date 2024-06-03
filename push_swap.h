#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft/libft.h"

typedef struct s_stack
{
	int		number;
	int 	temp;
	struct s_stack	*next;
}					t_stack;

//All needed for create stack 
void free_stack(t_stack *stack);
t_stack	*ft_lstnew2(int content);
int	ft_stacksize(t_stack *stack);
void create_node(t_stack **stack, const char *content);
void create_stack(t_stack **stack, int argc, char **argv);
//Access node value
int node_number(t_stack **stack, int n2);
int node_temp(t_stack **stack, int n2);
//All moves 
void move_swap(t_stack **stack);
void move_reverse(t_stack **stack);
void	move_rreverse(t_stack **stack);
void	move_push(t_stack **dest, t_stack **src);
#endif