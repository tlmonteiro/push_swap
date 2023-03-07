/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:57:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/07 22:37:16 by tlemos-m         ###   ########.fr       */
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
	/* while (stack_a)
	{
		if ((*stack_a)->rank == 1)
			break ;
		if ((*stack_a)->rank <= 3)
			reverse_rotate(stack_a, 'a');
		else
			rotate(stack_a, 'a');
	} */
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
				put_in_place(stack_a, 'a', moves.x);
			else
				put_in_place(stack_b, 'b', moves.y);
		}
		print_stack(stack_a, 'a');
		print_stack(stack_b, 'b');
	}
	arrange_stack(stack_a);
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	return ;
}

void	pivoting(t_list **stack_a, t_list **stack_b)
{
	t_atb	seq_head;
	int		size_a;
	int		i;

	seq_head = sequence_finder(*stack_a);
	while (*stack_a)
	{
		if ((*stack_a)->rank != seq_head.y)
			push(stack_a, stack_b, 'b');
		if ((*stack_a)->rank == seq_head.y)
			break ;
	}
	size_a = lstsize(*stack_a);
	i = size_a - seq_head.x;
	if (seq_head.x <= (size_a / 2))
	{
		while (seq_head.x-- > 0)
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
		if ((*stack_a)->rank != seq_head.y)
			push(stack_a, stack_b, 'b');
		if ((*stack_a)->rank == seq_head.y)
			break ;
	}
	return ;
}
