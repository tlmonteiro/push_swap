/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:28:46 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/27 16:23:00 by tlemos-m         ###   ########.fr       */
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
		temp = temp->next;
		if (temp == stack)
			break ;
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
	node->next = *stack;
	node->prev = (*stack)->prev;
	(*stack)->prev->next = node;
	(*stack)->prev = node;
	*stack = node;
	return ;
}

void	lstadd_back(t_list **stack, t_list *node)
{
	lstadd_front(stack, node);
	*stack = (*stack)->next;
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
		temp = temp->next;
		if (temp == stack)
			break ;
	}
	return (i);
}
