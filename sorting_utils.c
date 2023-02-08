/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:57:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/08 14:50:54 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack)
{
	int	first;
	int	mid;
	int	last;

	first = (*stack)->rank;
	mid = (*stack)->next->rank;
	last = lstlast(*stack)->rank;
	if (first > last && mid < last)
		rotate(stack, 'a');
	if (first > mid && mid < last)
		swap(stack, 'a');
	else if (first < mid && mid > last)
		reverse_rotate(stack, 'a');
}

/* void	sort_five(t_list **stack_a, t_list **stack_b)
{
	//find min to push to b
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	sort_three(stack_a);
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
} */
