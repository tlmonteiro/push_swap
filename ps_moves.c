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

	temp = (*stack)->next;
	(*stack)->next->next->prev = *stack;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->prev = NULL;
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
	if ((*stack_a)->next == NULL)
	{
		*stack_a = NULL;
		temp->next = NULL;
	}	
	else
	{
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
	}
	lstadd_front(stack_b, temp);
	printf("pa\n");
	return ;
}

void	push_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*temp;

	temp = *stack_b;
	if ((*stack_b)->next == NULL)
	{
		*stack_b = NULL;
		temp->next = NULL;
	}	
	else
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	lstadd_front(stack_a, temp);
	printf("pb\n");
	return ;
}

void	rotate(t_list **stack, char letter)
{
	t_list	*first;
	t_list	*last;

	first = (*stack)->next;
	first->prev = NULL;
	last = lstlast(*stack);
	(*stack)->next = NULL;
	(*stack)->prev = last;
	last->next = *stack;
	*stack = first;
	if (letter == 'a')
		printf("ra\n");
	if (letter == 'b')
		printf("rb\n");
	return ;
}

void	reverse_rotate(t_list **stack, char letter)
{
	t_list	*temp;
	t_list	*last;

	temp = lstlast(*stack);
	last = temp->prev;
	temp->prev = NULL;
	last->next = NULL;
	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = temp;
	if (letter == 'a')
		printf("rra\n");
	if (letter == 'b')
		printf("rrb\n");
	return ;
}
