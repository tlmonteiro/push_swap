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

int	check_min(t_list *stack_a, t_list *stack_b)
{
	int		total;
	int		new_min;
	int		moves_a;
	int		moves_b;
	t_list	*head_b;

	new_min = 0;
	head_b = stack_b;
	while (stack_b)
	{
		moves_b = count_moves(stack_b->rank, stack_b);
		if (moves_b < 0)
			moves_b *= -1;
		moves_a = check_to_push(stack_a, stack_b->rank);
		if (moves_a < 0)
			moves_a *= -1;
		total = moves_a + moves_b;
		printf("node_a: %i node_b: %i\tma: %i + mb: %i = total: %i\n",
			stack_a->value, stack_b->value, moves_a, moves_b, total);
		if (total <= new_min)
			new_min = total;
		stack_b = stack_b->next;
		if (stack_b == head_b)
			break ;
	}
	return (new_min);
}
