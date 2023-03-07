/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:04 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/27 17:02:56 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	store_total_moves(int moves_a, int moves_b, int total);

int	put_in_place(t_list **stack, char letter, int counter)
{
	int	size;

	size = lstsize(*stack);
	if (counter > (size / 2))
	{
		reverse_rotate(stack, letter);
		counter++;
	}
	else if (counter != 0)
	{
		rotate(stack, letter);
		counter--;
	}
	if (counter >= size)
		counter = 0;
	return (counter);
}

int	count_moves(int rank, t_list *stack)
{
	int		size;
	int		counter;
	t_list	*head;

	size = lstsize(stack);
	counter = 0;
	head = stack;
	while (stack)
	{
		if (rank == stack->rank)
			break ;
		counter++;
		stack = stack->next;
	}
	stack = head;
	if (counter > (size / 2))
		counter = (size - counter) * -1;
	return (counter);
}

int	check_min(t_list *stack_a, int moves_a, t_list *stack_b, int moves_b)
{
	int		min_moves;
	int		total;
	int		min_a;
	int		min_b;
	t_list	*head_b;

	min_moves = 500;
	total = min_moves;
	head_b = stack_b;
	while (head_b)
	{
		total = store_total_moves(check_to_push(stack_a, head_b->rank),
				count_moves(head_b->rank, stack_b), total);
		if (total < min_moves)
		{
			min_moves = total;
			min_a = moves_a;
			min_b = moves_b;
		}
		head_b = head_b->next;
		if (head_b == stack_b)
			break ;
	}
	moves_a = min_a;
	moves_b = min_b;
	return (min_moves);
}

int	store_total_moves(int moves_a, int moves_b, int total)
{
	printf("moves A: %i\tmoves B: %i\n", moves_b, moves_a);
	if (moves_a < 0 && moves_b < 0)
		total = (moves_a * -1) + (moves_b * -1);
	else if (moves_a < 0 && moves_b > 0)
		total = (moves_a * -1) + moves_b;
	else if (moves_a > 0 && moves_b < 0)
		total = moves_a + (moves_b * -1);
	else
		total = moves_a + moves_b;
	return (total);
}
