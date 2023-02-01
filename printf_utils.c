/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:19:04 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/27 14:48:53 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list **stack, char letter)
{
	t_list	*temp;

	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\t rank: %d\n", temp->value, temp->rank);
		temp = temp->next;
	}
	printf("---\t\t\t\n");
	printf("%c\t\t\t\n\n", letter);
	return ;
}