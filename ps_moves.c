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
		printf("sa\n");
	if (letter == 'b')
		printf("sb\n");
	return ;
}

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_a;
	if ((*stack_a)->next == *stack_a)
	{
		*stack_a = NULL;
		temp->next = NULL;
	}	
	else
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = temp->prev;
		temp->prev->next = *stack_a;
		temp->next = 0;
		temp->prev = 0;
	}
	lstadd_front(stack_b, temp);
	printf("pa\n");
	return ;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	if ((*stack_b)->next == *stack_b)
	{
		*stack_b = 0;
		temp->next = 0;
	}	
	else
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = lstlast(*stack_b);
	}
	lstadd_front(stack_a, temp);
	printf("pb\n");
	return ;
}

void	rotate(t_list **stack, char letter)
{
	*stack = (*stack)->next;
	if (letter == 'a')
		printf("ra\n");
	if (letter == 'b')
		printf("rb\n");
	return ;
}

void	reverse_rotate(t_list **stack, char letter)
{
	*stack = (*stack)->prev;
	if (letter == 'a')
		printf("rra\n");
	if (letter == 'b')
		printf("rrb\n");
	return ;
}
