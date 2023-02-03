/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:38:23 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/03 14:06:30 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_list **stack_a, t_list **stack_b)
{
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	swap(stack_a, 's');
	swap(stack_b, 's');
	printf("ss\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
}

void	double_rotate(t_list **stack_a, t_list **stack_b)
{
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	printf("rr\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	return ;
}

void	double_reverse_rotate(t_list **stack_a, t_list **stack_b)
{
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	reverse_rotate(stack_a, 'r');
	reverse_rotate(stack_b, 'r');
	printf("rrr\n");
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	return ;
}
