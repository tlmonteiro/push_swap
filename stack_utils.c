/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:43:12 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/02/27 11:38:10 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rank(t_list *stack)
{
	int		rank;
	t_list	*head;
	t_list	*node;

	head = stack;
	node = stack;
	while (stack)
	{
		rank = 1;
		node = head;
		while (node)
		{
			if (stack->value > node->value)
				rank += 1;
			node = node->next;
			if (node == head)
				break ;
		}
		stack->rank = rank;
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return ;
}

int	check_sorted(t_list **stack)
{
	t_list	*head;
	int		i;

	head = *stack;
	i = 1;
	while (*stack)
	{
		if ((*stack)->rank > (*stack)->next->rank)
		{
			i = 0;
			break ;
		}
		*stack = (*stack)->next;
		i++;
		if ((*stack)->next == head)
			break ;
	}
	*stack = head;
	return (i);
}

void	check_to_pull(t_list **stack_a, t_list **stack_b)
{
	int		flag;
	t_list	*head_a;

	flag = 0;
	head_a = *stack_a;
	while (*stack_a)
	{
		if ((*stack_b)->rank < (*stack_a)->rank
			&& (*stack_a)->prev->rank > (*stack_a)->rank)
			break ;
		else if ((*stack_b)->rank > (*stack_a)->prev->rank
			&& (*stack_a)->rank < (*stack_a)->prev->rank)
			break ;
		else if ((*stack_a)->prev->rank < (*stack_b)->rank
			&& (*stack_a)->rank > (*stack_b)->rank)
			break ;
		flag++;
		*stack_a = (*stack_a)->next;
		if (*stack_a == head_a)
			break ;
	}
	*stack_a = head_a;
	while (flag != 0)
		flag = put_in_place(stack_a, 'a', flag);
	return ;
}

void	check_to_push(t_list **stack, char letter, int pivot)
{
	int		min_moves;
	int		node_moves;
	t_list	*head;

	min_moves = 500;
	node_moves = 0;
	head = *stack;
	while (*stack)
	{
		if ((*stack)->rank <= pivot)
		{
			if (node_moves < min_moves)
				min_moves = node_moves;
		}	
		node_moves++;
		*stack = (*stack)->next;
		if (*stack == head)
			break ;
	}
	while (min_moves != 0)
		min_moves = put_in_place(stack, letter, min_moves);
	return ;
}
