/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguelcosta <miguelcosta@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:00 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/03 21:25:07 by miguelcosta      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				temp;
	int 			r_move;
	int 			rr_move;
	int				bf;
	int move_together;
	struct s_stack	*next;
}					t_stack;

//Main functions
void				push_swap(t_stack *stack_a, t_stack *stack_b);

void print_stack(t_stack **stack);

//Stack funtions
int					ft_stacksize(t_stack *stack);
t_stack				*ft_lstnew2(int content);
void				create_stack(t_stack **stack, int argc, char **argv);
void				free_stack(t_stack *stack);

//Get values
int					node_number(t_stack **stack, int n2);
int					node_temp(t_stack **stack, int n2);

//Moves
void				move_swap(t_stack **stack, char *move);
void				move_reverse(t_stack **stack, char *move);
void				move_rreverse(t_stack **stack, char *move);
void				move_push(t_stack **dest, t_stack **src, char *move);

int move_together(int ra, int rra, int rb, int rrb);
// Verify if it is sorted
int					sort(t_stack *stack);

//FULL ALGORITHM
//Function that sort the stack
void	sort_stack(t_stack **stack_a, t_stack **stack_b);



//Put how many moves to put the number on top of stack
void count_moves(t_stack *stack_a);

//Calculate how many moves to move to the top of the stack;
int	ft_distance(t_stack *stack, int number);

// Finds the bf and the best moves to do 
void find_bf(t_stack *stack_a, t_stack *stack_b, int minimum, int max);

// Applys the best move
void ft_move(t_stack **stack_a, t_stack **stack_b);

void print_all(t_stack **stack_a);
#endif