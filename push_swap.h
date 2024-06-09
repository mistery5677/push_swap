#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include "libft/libft.h"

typedef struct s_stack
{
	int		number;
	int 	temp;
	struct s_stack	*next;
}					t_stack;

//Main function
void push_swap(int argc, char **argv);

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
void move_rreverse(t_stack **stack);
void move_push(t_stack **dest, t_stack **src);

//Verify if the list is sorted
int sort(t_stack *stack);

//Sort the stack
void sort_stack(t_stack *stack_a, t_stack *stack_b);
void first_sort(t_stack **stack_a, t_stack **stack_b);

//Gets the lower value
int lower_number(t_stack *stack_a, t_stack *stack_b);
int find_stack(t_stack *stack_a, t_stack *stack_b, int minimum);
int find_lower(t_stack *stack, int limit, int safe);

//Calculate the distances
int ft_distance(t_stack *stack, int number); 


void print_stack(t_stack **stack);
#endif