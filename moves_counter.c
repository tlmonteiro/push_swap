/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:04 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/08 14:00:06 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//DO ROTATION if return < 0
//DO REVERSE ROTATION if return > 0
int	moves_to_top(t_list *stack, int argc)
{
	int		counter;
	t_list	*temp;

	counter = 0;
	temp = stack;
	while (temp->prev != NULL)
	{
		counter++;
		temp = temp->prev;
	}
	if (counter == 0)
		return (counter);
	if (counter > ((argc - 1) / 2))
		counter = (argc - counter - 1) * -1;
	return (counter);
}
