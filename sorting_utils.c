/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:57:36 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:37:16 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pivoting(t_list **stack_a, t_list **stack_b, int size);

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
	push(stack_a, stack_b, 'a');
	push(stack_a, stack_b, 'a');
	while (check_sorted(stack_a) == 0)
		sort_three(stack_a);
	check_to_pull(stack_a, stack_b);
	push(stack_b, stack_a, 'b');
	check_to_pull(stack_a, stack_b);
	push(stack_b, stack_a, 'b');
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
	int	size;

	size = lstsize(*stack_a);
	pivoting(stack_a, stack_b, size);
	return ;
}

void	pivoting(t_list **stack_a, t_list **stack_b, int size)
{
	int		round;
	t_list	*head;

	round = 1;
	head = *stack_a;
	while (round < PIVOT)
	{
		while (stack_a)
		{
			if ((*stack_a)->rank <= ((size / PIVOT) * round))
			{
				push(stack_a, stack_b, 'a');
				if (lstsize(*stack_b) > 1)
					check_to_push(*stack_a, stack_b);
				head = *stack_a;
			}
			else
				*stack_a = (*stack_a)->next;
			if ((*stack_a)->next == head)
				break ;
		}
		print_stack(stack_b, 'b');
		round++;
	}
	print_stack(stack_a, 'a');
	print_stack(stack_b, 'b');
	return ;
}
