/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:12 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/19 14:56:17 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rank(t_list *stack)
{
	int	final_rank;
	t_list	*temp;
	t_list	*node;

	node = stack;
	temp = NULL;
	final_rank = 1;
	while (node)
	{
		final_rank = 1;
		temp = stack;
		while (temp)
		{
			if (node->value == temp->value)
			{
				if (temp->next == NULL)
					break ;
				temp = temp->next;
			}
			if (node->value > temp->value)
				final_rank += 1;
			temp = temp->next;
		}
		node->rank = final_rank;
		node = node->next;
	}
	return ;
}
