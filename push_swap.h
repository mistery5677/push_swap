/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miafonso <miafonso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:36:00 by miafonso          #+#    #+#             */
/*   Updated: 2024/06/11 17:30:00 by miafonso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				temp;
	struct s_stack	*next;
}					t_stack;

void				push_swap(t_stack *stack_a, t_stack *stack_b);
void				free_stack(t_stack *stack);
t_stack				*ft_lstnew2(int content);
int					ft_stacksize(t_stack *stack);
void				create_node(t_stack **stack, const char *content);
void				create_stack(t_stack **stack, int argc, char **argv);
int					node_number(t_stack **stack, int n2);
int					node_temp(t_stack **stack, int n2);
void				move_swap(t_stack **stack);
void				move_reverse(t_stack **stack);
void				move_rreverse(t_stack **stack);
void				move_push(t_stack **dest, t_stack **src);
int					sort(t_stack *stack);
void				ft_sort_stacka(t_stack **stack_a, t_stack **stack_b,
						int distance, int midium);
void				ft_sort_stackb(t_stack **stack_b, t_stack **stack_a,
						int distance);
void				sort_stack(t_stack **stack_a, t_stack **stack_b, int midium);
int 				first_lower(t_stack *stack);
int					lower_number(t_stack *stack_a, t_stack *stack_b);
int					find_stack(t_stack *stack_a, t_stack *stack_b, int minimum);
int					ft_distance(t_stack *stack, int number);
void				print_stack(t_stack **stack);

//Algorithm
int ft_near_higher(t_stack *stack, int number);
int ft_near_lower(t_stack *stack, int number);

#endif