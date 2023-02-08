/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:53:24 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/08 14:57:23 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;

	stack = 0;
	if (argc > 1)
	{
		if (argc > 2)
		{
			if (check_doubles(argv) == 0)
				exit(0);
		}
		stack = parse_arg(argv, argc);
		free_stack(&stack);
	}
	return (0);
}
