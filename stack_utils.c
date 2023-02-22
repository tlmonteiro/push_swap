/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:12 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/22 13:27:04 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rank(t_list *stack)
{
	int		rank;
	t_list	*head;
	t_list	*node;

	head = stack;
	node = stack;
	while (stack)
	{
		rank = 1;
		node = head;
		while (node)
		{
			if (stack->value > node->value)
				rank += 1;
			node = node->next;
			if (node == head)
				break ;
		}
		stack->rank = rank;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return ;
}

int	check_sorted(t_list **stack)
{
	t_list	*head;
	int		i;

	head = *stack;
	i = 1;
	while (*stack)
	{
		if ((*stack)->rank > (*stack)->next->rank)
		{
			i = 0;
			break ;
		}
		*stack = (*stack)->next;
		i++;
		if ((*stack)->next == head)
			break ;
	}
	*stack = head;
	return (i);
}
