/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:28:46 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/13 10:31:32 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_lstnew(long int value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = value;
	//new->rank = rank;
	new->next = NULL;
	return (new);
}

t_list	*ps_lstlast(t_list *stack)
{
	int	i;

	i = 1;
	if (!stack)
		return (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
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
	temp->next = node;
}
