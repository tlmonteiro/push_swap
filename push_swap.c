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

void	choose_sorting(int argc, t_list **stack_a, t_list **stack_b);

void	push_swap(char **argv, int argc)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = parse_arg(0, argv, argc);
	stack_b = 0;
	if (check_sorted(&stack_a) == 0)
		choose_sorting(argc, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return ;
}

void	choose_sorting(int argc, t_list **stack_a, t_list **stack_b)
{
	int	flag;

	flag = 0;
	if (argc == 3 && flag == 0)
		swap(stack_a, 'a');
	if (argc == 4)
	{
		while (flag == 0)
		{
			sort_three(stack_a);
			flag = check_sorted(stack_a);
		}
	}
	else if (argc == 6)
		sort_five(stack_a, stack_b);

	else if (argc > 100)
		sort_hundreds(stack_a, stack_b);
}
