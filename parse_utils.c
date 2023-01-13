/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:11:11 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/13 10:32:02 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	check_input(const char *nptr);

t_list	**parse_arg(char **argv, int argc)
{
	t_list		**stack_a;
	int			i;
	long int	value;

	*stack_a = NULL;
	while (argv[i])
	{
		if (!check_input(argv[i]))
			exit(0);
		i++;
	}
	i = 0;
	while (argv[i])
	{
		value = ft_atoli(argv[i]);
		ps_lstadd_back(*stack_a, ps_lstnew(value));
		i++;
	}
	return (*stack_a);
}

long int	check_input(const char *nptr)
{
	int				i;
	int				value;

	i = 0;
	if ((nptr[i] == '-' || nptr[i] == '+') && !ft_isdigit(nptr[i + 1]))
		return (write(2, "Error\n", 6));
	while (nptr[i])
	{
		if (nptr[i] == '-')
			i++;
		if (!ft_isdigit(nptr[i]))
			return (write(2, "Error\n", 6));
		i++;
	}
	if (!ft_atoli(nptr))
		return (write(2, "Error\n", 6));
	value = ft_atoli(nptr);
	return (value);
}
