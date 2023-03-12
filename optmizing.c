/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmizing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:26:53 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/12 19:38:03 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_next(t_list *stack_a, t_atb seq, int round, int size_a)
{
	t_list	*temp;
	t_list	*next;
	int		i;

	temp = stack_a;
	i = size_a;
	while (temp)
	{
		check_skip_sequence(&temp, seq);
		next = temp->next;
		while (next != stack_a)
		{
			check_skip_sequence(&next, seq);
			if (temp->rank <= next->rank && temp->rank <= i)
				i = temp->rank;
			if (temp == next)
				break ;
			next = next->next;
		}
		temp = temp->next;
		if (temp == stack_a || lstsize(stack_a) == seq.x + 1)
			break ;
	}
	while (i > (size_a * round) / PIVOT)
		round++;
	return (round);
}

void	check_skip_sequence(t_list **node, t_atb seq)
{
	int	i;

	i = seq.x;
	if ((*node)->value == seq.y)
	{
		while (i--)
			*node = (*node)->next;
	}
	return ;
}
