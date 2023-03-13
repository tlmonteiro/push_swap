/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:57:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/13 16:12:09 by tlemos-m         ###   ########.fr       */
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
	last = (*stack)->prev->rank;
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
	arrange_stack(stack_a);
	return ;
}

void	sort_hundreds(t_list **stack_a, t_list **stack_b)
{
	t_atb	moves;

	moves.x = 0;
	moves.y = 0;
	pivoting(stack_a, stack_b);
	while (*stack_b != 0)
	{
		moves = check_min(*stack_a, moves.x, *stack_b, moves.y);
		if (moves.x * moves.y > 0)
			push_same(stack_a, moves.x, stack_b, moves.y);
		else if (moves.x * moves.y < 0)
			push_opposites(stack_a, moves.x, stack_b, moves.y);
		else
		{
			if (moves.x == 0 && moves.y == 0)
				push(stack_b, stack_a, 'a');
			else if (moves.x != 0)
				moves.x = put_in_place(stack_a, 'a', moves.x);
			else
				moves.y = put_in_place(stack_b, 'b', moves.y);
		}
	}
	arrange_stack(stack_a);
	return ;
}

int	get_tail(t_list *stack_a, t_atb seq)
{
	int	rank;
	int	s_size;

	rank = 0;
	s_size = seq.x;
	while (stack_a)
	{
		if (stack_a->value == seq.y)
		{
			while (s_size--)
			{
				rank = stack_a->rank;
				stack_a = stack_a->next;
			}
		}
		if (s_size <= 0)
			break ;
	}
	return (rank);
}
