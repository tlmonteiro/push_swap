/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmizing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:26:53 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/08 18:05:10 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_rev_sort(t_list **stack_b)
{
	t_list	*head_b;
	int		size_b;
	int		i;

	i = 0;
	size_b = lstsize(*stack_b);
	head_b = *stack_b;
	while (*stack_b && size_b > 1)
	{
		if ((*stack_b)->rank < (*stack_b)->next->rank)
			break ;
		i++;
		*stack_b = (*stack_b)->next;
		if ((*stack_b)->next == head_b)
			break ;
	}
	*stack_b = head_b;
	if (i < size_b)
		i = 0;
	return (i);
}

void	ready_to_pull(t_list **stack_a, t_list **stack_b)
{
	int		size_b;
	int		i;
	t_list	*head_b;

	size_b = lstsize((*stack_b));
	i = 0;
	head_b = *stack_b;
	if (check_rev_sort(stack_b) > 0)
	{
		if ((*stack_b)->rank < (*stack_a)->rank)
		{
			while (*stack_b)
			{
				if ((*stack_a)->rank < (*stack_b)->rank)
					i++;
				*stack_b = (*stack_b)->next;
				if (*stack_b == head_b)
					break ;
			}
			while (i)
				i = put_in_place(stack_b, 'b', i);
		}
	}
	return ;
}
