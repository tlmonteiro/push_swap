/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:28:46 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/11 15:50:55 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ps_lstnew(struct s_list **stack, long int value)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return ;
	node->value = value;
	node->rank = rank;
	node->next = NULL;
	ps_lstadd_back(*stack, node);
	return (node);
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
