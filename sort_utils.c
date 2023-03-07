/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:04 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/07 23:26:54 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	store_total_moves(int moves_a, int moves_b);

int	put_in_place(t_list **stack, char letter, int counter)
{
	int	size;

	size = lstsize(*stack);
	if (counter > (size / 2) || counter < 0)
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

void	arrange_stack(t_list **stack)
{
	int	size;

	size = lstsize(*stack);
	while (stack)
	{
		if ((*stack)->rank == 1)
			break ;
		if ((*stack)->rank <= (size / 2) + 1)
			reverse_rotate(stack, 'a');
		else
			rotate(stack, 'a');
	}
	return ;
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

t_atb	check_min(t_list *stack_a, int moves_a, t_list *stack_b, int moves_b)
{
	int		min_moves;
	int		total;
	t_atb	moves;
	t_list	*head_b;

	min_moves = 500;
	head_b = stack_b;
	while (head_b)
	{
		moves_a = check_to_push(stack_a, head_b->rank);
		moves_b = count_moves(head_b->rank, stack_b);
		total = store_total_moves(moves_a, moves_b);
		if (min_moves > total)
		{
			moves.x = moves_a;
			moves.y = moves_b;
			min_moves = total;
		}
		head_b = head_b->next;
		if (head_b == stack_b || min_moves == 0)
			break ;
	}
	printf("moves A: %i\tmoves B: %i\ttotal: %i\n", moves_a, moves_b, min_moves);
	return (moves);
}

int	store_total_moves(int moves_a, int moves_b)
{
	int	total;
	int	signal;

	signal = -1;
	total = 0;
	if (moves_a < 0 && moves_b < 0)
		total = (moves_a + moves_b) * signal;
	else if (moves_a < 0 && moves_b >= 0)
		total = ((moves_a * signal) + moves_b);
	else if (moves_a >= 0 && moves_b < 0)
		total = (moves_a + (moves_b * signal));
	else
		total = moves_a + moves_b;
	return (total);
}
