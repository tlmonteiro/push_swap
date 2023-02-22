/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:07:09 by marvin            #+#    #+#             */
/*   Updated: 2023/02/22 13:01:52 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(char **argv, int argc)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		flag;

	stack_a = parse_arg(0, argv, argc);
	stack_b = 0;
	flag = check_sorted(&stack_a);
	if (argc == 4)
	{
		while (flag == 0)
		{
			sort_three(&stack_a);
			flag = check_sorted(&stack_a);
		}
	}
	if (stack_b != 0)
		print_stack(&stack_b, 'b');
	else if (argc == 6)
	{
		sort_five(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return ;
}
