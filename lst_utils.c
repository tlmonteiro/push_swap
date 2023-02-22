/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:28:46 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/22 15:18:09 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lstnew(int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->value = value;
	new->rank = 0;
	new->prev = 0;
	new->next = 0;
	return (new);
}

t_list	*lstlast(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	if (!stack)
		return (0);
	while (temp)
	{
		if (temp->next == stack)
			break ;
		temp = temp->next;
	}
	return (temp);
}

void	lstadd_front(t_list **stack, t_list *node)
{
	if (!*stack)
	{
		*stack = node;
		(*stack)->next = node;
		(*stack)->prev = node;
		return ;
	}
	node->next = (*stack)->next;
	node->prev = *stack;
	(*stack)->next->prev = node;
	(*stack)->next = node;
	*stack = node;
	return ;
}

void	lstadd_back(t_list **stack, t_list *node)
{
	t_list	*head;

	if (!*stack)
	{
		*stack = node;
		(*stack)->next = node;
		(*stack)->prev = node;
		return ;
	}
	head = *stack;
	if ((*stack)->prev != *stack)
		*stack = (*stack)->prev;
	lstadd_front(stack, node);
	*stack = head;
	return ;
}

int	lstsize(t_list *stack)
{
	int		i;
	t_list	*temp;

	temp = stack;
	i = 0;
	if (!stack)
		return (0);
	while (temp)
	{
		i++;
		if (temp->next == stack)
			break ;
		temp = temp->next;
	}
	return (i);
}
