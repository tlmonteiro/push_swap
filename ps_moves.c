/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:46:59 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/17 10:28:21 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**stack, char letter)
{
	t_list	*temp;
	t_list	*last;

	temp = (*stack)->next;
	last = lstlast(*stack);
	temp->prev = last;
	last->next = temp;
	(*stack)->next->next->prev = *stack;
	(*stack)->prev = temp;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	*stack = temp;
	if (letter == 'a')
		write(1, "sa\n", 3);
	if (letter == 'b')
		write(1, "sb\n", 3);
	return ;
}

void	push(t_list **src, t_list **dest, char letter)
{
	t_list	*temp;

	temp = *src;
	if ((*src)->next->value == (*src)->value)
		*src = 0;
	else
	{
		*src = (*src)->next;
		(*src)->prev = temp->prev;
		temp->prev->next = *src;
	}
	lstadd_front(dest, temp);
	if (letter == 'a')
		write(1, "pa\n", 3);
	if (letter == 'b')
		write(1, "pb\n", 3);
	return ;
}

void	rotate(t_list **stack, char letter)
{
	*stack = (*stack)->next;
	if (letter == 'a')
		write(1, "ra\n", 3);
	if (letter == 'b')
		write(1, "rb\n", 3);
	return ;
}

void	reverse_rotate(t_list **stack, char letter)
{
	*stack = (*stack)->prev;
	if (letter == 'a')
		write(1, "rra\n", 4);
	if (letter == 'b')
		write(1, "rrb\n", 4);
	return ;
}
