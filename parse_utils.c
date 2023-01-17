/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:11:11 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/13 13:24:08 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_input(const char *nptr);
int			check_doubles(char **argv);
void		free_list(t_list *stack);

t_list	**parse_arg(char **argv)
{
	t_list		**stack_a;
	int			i;
	long long	value;

	stack_a = NULL;
	i = 0;
	while (argv[i])
	{
		if (check_input(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	i = 0;
	while (argv[i])
	{
		value = ft_atoll(argv[i]);
		printf("%lld\n", value);
		//ps_lstadd_back(stack_a, ps_lstnew(value));
		i++;
	}
	return (stack_a);
}

int	check_doubles(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while(argv[j])
		{
			if(ft_atoll(argv[i]) == ft_atoll(argv[j]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_input(const char *nptr)
{
	int	i;

	i = 0;
	if ((nptr[i] == '-' || nptr[i] == '+') && !ft_isdigit(nptr[i + 1]))
		return (0);
	while (nptr[i])
	{
		if (nptr[i] == '-')
			i++;
		if (!ft_isdigit(nptr[i]))
			return (0);
		i++;
	}
	if (ft_atoll(nptr) < INT_MIN || ft_atoll(nptr) > INT_MAX)
		return (0);
	return (1);
}
