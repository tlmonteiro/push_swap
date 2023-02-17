/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:12 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/17 11:07:19 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	update_rank(t_list *temp, t_list *node, int rank);

void	get_rank(t_list *stack)
{
	int		final_rank;
	t_list	*temp;
	t_list	*node;

	node = stack;
	temp = NULL;
	while (node)
	{
		final_rank = 1;
		temp = stack;
		final_rank = update_rank(temp, node, final_rank);
		node->rank = final_rank;
		node = node->next;
	}
	return ;
}

int	update_rank(t_list *temp, t_list *node, int rank)
{
	while (temp)
	{
		if (node->value == temp->value)
		{
			if (temp->next == NULL)
				break ;
			temp = temp->next;
		}
		if (node->value > temp->value)
			rank += 1;
		temp = temp->next;
	}
	return (rank);
}

int	check_sorted(t_list **stack)
{
	t_list	*temp;
	t_list	*t_next;
	int		i;

	t_next = (*stack)->next;
	i = 1;
	while (t_next != NULL)
	{
		temp = t_next->prev;
		if (t_next->rank < temp->rank)
		{
			i = 0;
			break ;
		}
		t_next = t_next->next;
		temp = temp->next;
		i++;
	}
	return (i);
}

int	check_min_moves(t_list **stack, int argc)
{
	int		moves;
	int		rank;
	t_list	*temp;

	temp = *stack;
	rank = temp->rank;
	while (temp)
	{
		moves = moves_to_top(temp, argc);
		if (moves < 0)
			moves *= -1;
		printf("moves to top: %i\n", moves);
		temp = temp->next;
	}
	return (rank);
}
