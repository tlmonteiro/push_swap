/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:28:46 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/19 14:49:19 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_lstnew(int value)
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

t_list	*ps_lstlast(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	if (!stack)
		return (0);
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

void	ps_lstadd_back(t_list **stack, t_list *node)
{
	t_list	*temp;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	temp = ps_lstlast(*stack);
	node->prev = temp;
	temp->next = node;
	return ;
}

int	ps_lstsize(t_list *stack)
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
	}
	return (i);
}

void	get_final_rank(t_list **stack)
{
	int		min_value;

	min_value = get_min(stack);
	return ;
}
