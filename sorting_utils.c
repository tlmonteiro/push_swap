/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:57:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/17 11:11:16 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_stack(t_list **stack_a, t_list **stack_b);

void	sort_three(t_list **stack)
{
	int	first;
	int	mid;
	int	last;

	first = (*stack)->rank;
	mid = (*stack)->next->rank;
	last = lstlast(*stack)->rank;
	if (first > mid && mid > last)
		swap(stack, 'a');
	else if (first > last && mid < last)
		rotate(stack, 'a');
	else if (first > mid && mid < last)
		swap(stack, 'a');
	else if (first < mid && mid > last)
		reverse_rotate(stack, 'a');
}

void	sort_five(t_list **stack_a, t_list **stack_b)
{
	push_a(stack_a, stack_b);
	push_a(stack_a, stack_b);
	while (check_sorted(stack_a) == 0)
		sort_three(stack_a);
	check_stack(stack_a, stack_b);
	check_stack(stack_a, stack_b);
	while (stack_a)
	{
		if ((*stack_a)->rank == 1)
			break ;
		else
			rotate(stack_a, 'a');
	}
	return ;
}

void	check_stack(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_b)->rank <= lstsize(*stack_a))
	{
		if (!((*stack_b)->rank == ((*stack_a)->rank - 1)))
			put_in_place(stack_a, (*stack_b)->rank);
	}
	push_b(stack_a, stack_b);
	return ;
}
