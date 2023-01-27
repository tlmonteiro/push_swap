/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:19:04 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/27 11:25:17 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **stack)
{
	t_list	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("Value: %d\tRank: %d\n", temp->value, temp->rank);
		temp = temp->next;
	}
	printf("---\t\t\t\n");
	printf("a\t\t\t\n");
	return ;
}
