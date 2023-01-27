/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:12 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/27 10:06:51 by tlemos-m         ###   ########.fr       */
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
