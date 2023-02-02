/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:04 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/02 13:04:59 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//DO ROTATION if return < 0
//DO REVERSE ROTATION if return > 0
int	moves_to_top(t_list *stack)
{
	int		counter;
	int		r_counter;
	t_list	*temp;

	counter = 0;
	temp = stack;
	while (temp->prev != NULL)
	{
		temp = temp->prev;
		counter++;
	}
	if (counter == 0)
		return (counter);
	temp = stack;
	r_counter = 0;
	while (temp)
	{
		temp = temp->next;
		r_counter++;
	}
	if (counter <= r_counter)
		return (counter);
	else
		return (r_counter * -1);
}
