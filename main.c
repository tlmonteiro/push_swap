/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:53:24 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/19 11:21:19 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*temp;

	stack = 0;
	if (argc > 1)
	{
		if (argc > 2)
		{
			if (check_doubles(argv) == 0)
				exit(0);
		}
		stack = parse_arg(argv, argc);
		temp = stack;
		while (temp != NULL)
		{
			printf("Value: %d\tRank: %d\n", temp->value, temp->rank);
			temp = temp->next;
		}
		printf("---\t\t\t\n");
		printf("a\t\t\t\n");
		free_stack(&stack);
	}
	return (0);
}
