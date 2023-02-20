/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:11:11 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/17 10:12:12 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_input(char *nptr);
int			check_doubles(char **argv);
void		initialize_stack(t_list **stack_a, int value);
void		free_stack(t_list **stack);

t_list	*parse_arg(t_list *stack, char **argv, int argc)
{
	int			i;
	int			value;

	i = 1;
	while (i < argc)
	{
		if (check_input(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		value = ft_atoi(argv[i]);
		initialize_stack(&stack, value);
		i++;
	}
	get_rank(stack);
	return (stack);
}

void	initialize_stack(t_list **stack_a, int value)
{
	t_list	*new_node;

	new_node = lstnew(value);
	if (!new_node)
		free_stack(stack_a);
	lstadd_back(stack_a, new_node);
	return ;
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		if ((*stack)->next != 0)
		{
			*stack = (*stack)->next;
			temp->next = 0;
		}
		temp->prev = 0;
		free(temp);
		if (!(*stack)->next)
			break ;
	}
	*stack = 0;
	return ;
}

int	check_doubles(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoll(argv[i]) == ft_atoll(argv[j]))
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

int	check_input(char *nptr)
{
	int			i;
	long long	value;

	i = 0;
	if ((nptr[i] == '-') && !ft_isdigit(nptr[i + 1]))
		return (0);
	if (nptr[i] == '-')
		i++;
	while (nptr[i])
	{
		if (!ft_isdigit(nptr[i]))
			return (0);
		i++;
	}
	value = ft_atoll(nptr);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	return (1);
}
