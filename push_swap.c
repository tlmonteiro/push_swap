/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:07:09 by marvin            #+#    #+#             */
/*   Updated: 2023/02/17 10:12:41 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list **stack_a, int argc)
{
	int		flag;
	t_list	*temp;
	t_list	*stack_b;

	temp = *stack_a;
	stack_b = 0;
	flag = check_sorted(stack_a);
	if (argc == 4)
	{
		while (flag == 0)
		{
			sort_three(stack_a);
			flag = check_sorted(stack_a);
		}
	}
	else if (argc == 6)
	{
		sort_five(stack_a, &stack_b);
	}
	return ;
}
