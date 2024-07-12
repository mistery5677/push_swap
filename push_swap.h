/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:00 by miafonso          #+#    #+#             */
/*   Updated: 2024/07/12 02:36:53 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				temp;
	int				r_move;
	int				rr_move;
	int				bf;
	int				move_together;
	struct s_stack	*next;
}					t_stack;

void				push_swap(t_stack *stack_a, t_stack *stack_b, int argc,
						char **argv);
void				ft_sort3(t_stack **stack_a, t_stack **stack_b);
int					check(t_stack *stack, char **argv);
int					ft_stacksize(t_stack *stack);
t_stack				*ft_lstnew2(int content);
void				create_stack(t_stack **stack, int argc, char **argv);
void				free_stack(t_stack *stack);
int					node_number(t_stack **stack, int n2);
int					node_temp(t_stack **stack, int n2);
void				move_swap(t_stack **stack, char *move);
void				move_reverse(t_stack **stack, char *move);
void				move_rreverse(t_stack **stack, char *move);
void				move_push(t_stack **dest, t_stack **src, char *move);
int					move_together(int ra, int rra, int rb, int rrb);
int					sort(t_stack *stack);
void				count_moves(t_stack *stack_a);
int					ft_distance(t_stack *stack, int number);
void				util_bf2(t_stack **lowest_node, t_stack *tmp_a,
						t_stack *tmp_b);
int					valid1(t_stack *tmp_a, t_stack *tmp_b, int minimum,
						int max);
int					valid2(t_stack *tmp_a, t_stack *tmp_b, t_stack *lowest_node,
						int last_nbr);
void				update_info(t_stack **stack_a, t_stack **stack_b,
						t_stack *b, int *last_nbr);
void				find_bf(t_stack *stack_a, t_stack *stack_b, int minimum,
						int max);
int					many_rr(t_stack *stack_a, t_stack *stack_b);
void				option_1(t_stack **stack_a, t_stack **stack_b, int ra,
						int rrb);
void				option_2(t_stack **stack_a, t_stack **stack_b, int rra,
						int rb);
void				option_3(t_stack **stack_a, t_stack **stack_b, int ra,
						int rb);
void				option_4(t_stack **stack_a, t_stack **stack_b, int rra,
						int rrb);
void				ft_move(t_stack **stack_a, t_stack **stack_b);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
int					find_minimum(t_stack *stack_a);
int					find_max(t_stack *stack_a);
void				final_sort(t_stack **stack_a, int minimum);
long long int		find_average(t_stack *stack_a);
void				push_b(t_stack **stack_a, t_stack **stack_b);
#endif