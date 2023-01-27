/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:46:59 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/27 14:59:47 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list	**stack, char letter)
{
	t_list	*temp;

	print_stack(stack);
	temp = (*stack)->next;
	(*stack)->prev = temp;
	(*stack)->next = temp->next;
	temp->next = *stack;
	temp->prev = NULL;
	*stack = temp;
	if (letter == 'a')
		printf("sa\n");
	if (letter == 'b')
		printf("sb\n");
	print_stack(stack);
	return ;
}

void	push(t_list **stack_a, t_list **stack_b, char letter)
{
	t_list	*temp;

	if (letter == 'a')
	{
		temp = *stack_a;
		temp->next = NULL;
		*stack_a = (*stack_a)->next;
		(*stack_a)->prev = NULL;
		ps_lstadd_front(stack_b, temp);
		printf("pa");
		print_stack(stack_a);
		print_stack(stack_b);
	}
	if (letter == 'b')
	{
		temp = *stack_b;
		temp->next = NULL;
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
		ps_lstadd_front(stack_a, temp);
		printf("pb");
	}
	return ;
}

void	rotate(t_list **stack, char letter)
{
	t_list	*first;
	t_list	*last;

	first = (*stack)->next;
	first->prev = NULL;
	last = ps_lstlast(*stack);
	(*stack)->next = NULL;
	(*stack)->prev = last;
	last->next = *stack;
	*stack = first;
	if (letter == 'a')
		printf("ra\n");
	if (letter == 'b')
		printf("rb\n");
	print_stack(stack);
	return ;
}

void	reverse_rotate(t_list **stack, char letter)
{
	t_list	*temp;
	t_list	*last;

	temp = ps_lstlast(*stack);
	last = temp->prev;
	last->next = NULL;
	temp->next = *stack;
	temp->prev = NULL;
	(*stack)->prev = temp;
	*stack = temp;
	if (letter == 'a')
		printf("rra\n");
	if (letter == 'b')
		printf("rrb\n");
	print_stack(stack);
	return ;
}
