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
long int		ft_atoi(const char *nptr);

char	*check_input(const char *nptr)
{
	int	i;
	int	value;

	i = 0;
	if (nptr[i] == "-" || nptr[i] == "+" && !ft_isdigit(nptr[i + 1]))
	{
		write (2, "Error\n", 6);
		return (0);
	}
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
		{
			write (2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	i = 0;
	if (ft_atoi(nptr[i]) < INT_MIN || ft_atoi(nptr[i]) > INT_MAX)
	{
		write (2, "Error\n", 6);
		return (0);
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c < 48 || c > 57)
		return (c);
	return (0);
}

long int	ft_atoi(const char *nptr)
{
	int			i;
	int			s;
	long int	res;

	i = 0;
	s = 1;
	res = 0;
	if (nptr[i] == "-")
	{
		s *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = ((res * 10) + (nptr[i] - '0'));
		i++;
	}
	return (res * s);
}
