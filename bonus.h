/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mistery576 <mistery576@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 00:52:31 by mistery576        #+#    #+#             */
/*   Updated: 2024/07/11 01:18:09 by mistery576       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_move(char *info, t_stack **stack_a, t_stack **stack_b);
void	r_move(char *info, t_stack **stack_a, t_stack **stack_b);
void	rr_move(char *info, t_stack **stack_a, t_stack **stack_b);
void	p_move(char *info, t_stack **stack_a, t_stack **stack_b);
void	verify_info(char *info, t_stack **stack_a, t_stack **stack_b);
