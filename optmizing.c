/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmizing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:26:53 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/09 20:09:29 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ready_to_push(t_list *stack_a, int size, int i)
{
	t_list	*head1;
	t_list	*head2;
	int		flag;

	flag = 0;
	head1 = stack_a;
	head2 = stack_a;
	while (stack_a)
	{
		if (head1->rank <= (size / PIVOT) * i && head1->rank < (size - 2))
			return (flag);
		if (head2->rank <= (size / PIVOT) * i && head2->rank < (size - 2))
			return (flag * -1);
		flag++;
		head1 = head1->next;
		head2 = head2->prev;
		if (head1 == stack_a || head2 == stack_a)
			break ;
	}
	return (0);
}
