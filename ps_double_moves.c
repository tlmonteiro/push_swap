/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_double_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:38:23 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/08 15:24:25 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_swap(t_list **stack_a, t_list **stack_b)
{
	swap(stack_a, 's');
	swap(stack_b, 's');
	write(1, "ss\n", 3);
}

void	double_rotate(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	write(1, "rr\n", 3);
	return ;
}

void	double_reverse_rotate(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a, 'r');
	reverse_rotate(stack_b, 'r');
	write(1, "rrr\n", 4);
	return ;
}
