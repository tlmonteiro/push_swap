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

int	get_min(t_list **stack)
{
	int		min;
	int		new_min;
	t_list	*temp;

	min = 1;
	new_min = 1;
	temp = ps_lstlast(*stack);
	while (temp->prev != NULL)
	{
		if (temp->value < temp->prev->value)
		{
			new_min = temp->value;
			if (temp->value < min)
				min = temp->value;
			temp->rank = ps_lstsize(temp->prev);
		}
		else if (temp->next != NULL)
			temp->rank = ps_lstsize(*stack);
		else
			temp->rank = ps_lstsize(temp);
		temp = temp->prev;
	}
	temp->rank = 1;
	min = temp->value;
	new_min = min;
	return (min);
}
