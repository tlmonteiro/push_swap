/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:07:09 by marvin            #+#    #+#             */
/*   Updated: 2023/02/10 14:38:29 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack, int argc)
{
	int		flag;
	t_list	*temp;

	temp = *stack;
	flag = check_sorted(stack);
	if (argc == 4)
	{
		while (flag == 0)
		{
			sort_three(stack);
			flag = check_sorted(stack);
		}
	}
	return ;
}
