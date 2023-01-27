/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:46:59 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/27 12:40:44 by tlemos-m         ###   ########.fr       */
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

/*void	push(t_list **stack_a, t_list **stack_b, char letter)
{
	return ;
}*/

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
