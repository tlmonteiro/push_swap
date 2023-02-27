/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:57:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/27 16:59:15 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivoting(t_list **stack_a, t_list **stack_b);

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
	push(stack_a, stack_b, 'b');
	push(stack_a, stack_b, 'b');
	while (check_sorted(stack_a) == 0)
		sort_three(stack_a);
	check_to_pull(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
	check_to_pull(stack_a, stack_b);
	push(stack_b, stack_a, 'a');
	while (stack_a)
	{
		if ((*stack_a)->rank == 1)
			break ;
		if ((*stack_a)->rank <= 3)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	}
	return ;
}

void	sort_hundreds(t_list **stack_a, t_list **stack_b)
{
	pivoting(stack_a, stack_b);
	return ;
}

void	pivoting(t_list **stack_a, t_list **stack_b)
{
	t_seq	s_head;
	int		size_a;
	int		i;

	s_head = sequence_finder(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->rank != s_head.rank)
			push(stack_a, stack_b, 'b');
		if ((*stack_a)->rank == s_head.rank)
			break ;
	}
	size_a = lstsize(*stack_a);
	i = size_a - s_head.size;
	if (s_head.size <= (size_a / 2))
	{
		while (s_head.size-- > 0)
			rotate(stack_a, 'a');
	}
	else
	{
		while (i--)
		{
			reverse_rotate(stack_a, 'a');
			push(stack_a, stack_b, 'b');
		}
	}
	while (*stack_a)
	{
		if ((*stack_a)->rank != s_head.rank)
			push(stack_a, stack_b, 'b');
		if ((*stack_a)->rank == s_head.rank)
			break ;
	}
	return ;
}