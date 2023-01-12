/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:59:50 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/11 17:03:29 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_isdigit(int c);
long int		ft_atoli(const char *nptr);

t_list **parse_arg(char **argv, int argc)
{
	struct s_list	**stack_a;

	*stack_a = malloc(sizeof(t_list) * (argc + 1));
	while (argv[i])
	{
		if(!check_input(argv[i]))
			break ;
		i++;
	}
	return (*stack_a);
}

long int	*check_input(const char *nptr)
{
	int				i;
	int				value;

	i = 0;
	if (nptr[0] == '-' || nptr[0] == '+' && !ft_isdigit(nptr[1]))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	while (nptr[i])
	{
		if (nptr[0] == '-')
			i++;
		if (!ft_isdigit(nptr[i]))
		{
			write (2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	if (!ft_atoi(nptr))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	value = ft_atoi(nptr);
	return (value);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (c);
	return (0);
}

long int	ft_atoli(const char *nptr)
{
	int			i;
	int			s;
	long int	res;

	i = 0;
	s = 1;
	res = 0;
	if (nptr[i] == '-')
	{
		s *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = ((res * 10) + (nptr[i] - '0'));
		i++;
	}
	if ((res * s) > INT_MAX || (res * s) < INT_MIN)
		return (0);
	return (res * s);
}
