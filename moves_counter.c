/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_counter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:01:04 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:14:39 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_helper(t_list **stack, int flag)
{
	while (flag != 0)
		flag = put_in_place(stack, flag);
	*stack = (*stack)->prev;
	return ;
}

int	put_in_place(t_list **stack, int counter)
{
	int	size;

	size = lstsize(*stack);
	if (counter > (size / 2))
	{
		reverse_rotate(stack, 'a');
		counter++;
	}
	else if (counter != 0)
	{
		rotate(stack, 'a');
		counter--;
	}
	if (counter >= size)
		counter = 0;
	return (counter);
}
