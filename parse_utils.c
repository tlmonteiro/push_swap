/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:11:11 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/01/27 14:52:49 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_input(char *nptr);
int			check_doubles(char **argv);
void		initialize_stack(t_list **stack_a, int value);
void		free_stack(t_list **stack);

t_list	*parse_arg(char **argv, int argc)
{
	int			i;
	int			value;
	t_list		*stack_a;
	t_list		*stack_b;

	i = 1;
	stack_a = 0;
	stack_b = 0;
	while (i < argc)
	{
		if (check_input(argv[i]) == 0)
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		value = ft_atoi(argv[i]);
		initialize_stack(&stack_a, value);
		i++;
	}
	get_rank(stack_a);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	push_a(&stack_a, &stack_b);
	free_stack(&stack_b);
	return (stack_a);
}

void	initialize_stack(t_list **stack_a, int value)
{
	t_list	*new_node;

	new_node = ps_lstnew(value);
	if (!new_node)
		free_stack(stack_a);
	ps_lstadd_back(stack_a, new_node);
	return ;
}

void	free_stack(t_list **stack)
{
	t_list	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		temp->next = 0;
		free(temp);
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
	int	i;
	int	value;

	i = 0;
	if ((nptr[i] == '-' || nptr[i] == '+') && !ft_isdigit(nptr[i + 1]))
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
