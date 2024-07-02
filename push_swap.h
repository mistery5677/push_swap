/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:00 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/02 00:24:46 by mistery576       ###   ########.fr       */
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

//Print stack
void print_stack(t_stack **stack);

//Main functions
void				push_swap(t_stack *stack_a, t_stack *stack_b);

//Stack funtions
void				free_stack(t_stack *stack);
t_stack				*ft_lstnew2(int content);
int					ft_stacksize(t_stack *stack);
void				create_stack(t_stack **stack, int argc, char **argv);

//Get values
int					node_number(t_stack **stack, int n2);
int					node_temp(t_stack **stack, int n2);

//Moves
void				move_swap(t_stack **stack, char *move);
void				move_reverse(t_stack **stack, char *move);
void				move_rreverse(t_stack **stack, char *move);
void				move_push(t_stack **dest, t_stack **src, char *move);

// Verify if it is sorted
int					sort(t_stack *stack);

//FULL ALGORITHM
//Function that sort the stack
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

//Sort only 3 numbers
void ft_sort3(t_stack **stack_a, t_stack **stack_b);

//Clear the stack_b, and sort stack_a
void sort_to_a(t_stack **stack_a, t_stack **stack_b);

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