/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:12 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/02 10:33:14 by tlemos-m         ###   ########.fr       */
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
	int		i;

	temp = *stack;
	i = 1;
	while (temp)
	{
		if (temp->rank != i)
		{
			i = 0;
			break ;
		}
		temp = temp->next;
		i++;
	}
	return (i);
}

/*int	check_min_moves(t_list **stack)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = *stack;
}*/
