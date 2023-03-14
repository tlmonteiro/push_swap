/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optmizing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:26:53 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/14 15:16:45 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		get_round(int i, int size_a, int round);
int		update_counter(t_list *temp, t_list *next, int i);
int		update_next(t_list *temp, t_list **next, t_atb seq, int i);
void	check_skip_sequence(t_list **node, t_atb seq);

int	check_next(t_list *stack_a, t_atb seq, int round, int size_a)
{
	t_list	*temp;
	t_list	*next;
	int		i;
	int		flag;
	t_list	*head;

	head = stack_a;
	if (head->value == seq.y)
		check_skip_sequence(&head, seq);
	temp = head;
	i = size_a;
	while (temp && lstsize(stack_a) > seq.x)
	{
		check_skip_sequence(&temp, seq);
		next = temp->next;
		flag = lstsize(stack_a) - seq.x;
		while (flag--)
			i = update_next(temp, &next, seq, i);
		temp = temp->next;
		check_skip_sequence(&temp, seq);
		if (temp == head || lstsize(stack_a) <= seq.x + 2)
			break ;
	}
	round = get_round(i, size_a, round);
	return (round);
}

int	get_round(int i, int size_a, int round)
{
	while (i > (size_a * round) / PIVOT)
		round++;
	return (round);
}

int	update_counter(t_list *temp, t_list *next, int i)
{
	if (temp->rank <= next->rank && temp->rank <= i)
		i = temp->rank;
	return (i);
}

int	update_next(t_list *temp, t_list **next, t_atb seq, int i)
{
	if (temp == *next)
		*next = (*next)->next;
	else if ((*next)->value != seq.y)
	{
		i = update_counter(temp, *next, i);
		*next = (*next)->next;
	}
	else
	{
		check_skip_sequence(next, seq);
		i = update_counter(temp, *next, i);
	}
	return (i);
}

void	check_skip_sequence(t_list **node, t_atb seq)
{
	int	i;

	i = seq.x;
	if ((*node)->value == seq.y)
	{
		while (i--)
			*node = (*node)->next;
	}
	return ;
}
