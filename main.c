/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:53:24 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/22 17:38:19 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	range;

	range = 21;
	if (argc > 1)
	{
		if (argc > 2)
		{
			if (check_doubles(argv) == 0)
				exit(0);
		}
		if (argc > 5)
			range = 43;
		printf("slice: %i\n", SLICE);
		//push_swap(argv, argc);
	}
	return (0);
}
