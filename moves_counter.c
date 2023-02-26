/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:04 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:14:39 by tlemos-m         ###   ########.fr       */
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
	int		counter;
	t_list	*head;

	counter = 0;
	head = stack;
	while (stack)
	{
		counter++;
		if (stack->next == head || stack->rank < rank)
			break ;
		stack = stack->next;
	}
	stack = head;
	return (counter);
}
