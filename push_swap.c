/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:07:09 by marvin            #+#    #+#             */
/*   Updated: 2023/03/14 15:52:24 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	choose_sorting(int argc, t_list **stack_a, t_list **stack_b);

void	push_swap(char **argv, int argc)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = parse_arg(0, argv, argc);
	stack_b = 0;
	if (check_sorted(&stack_a) == 0)
		choose_sorting(argc, &stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return ;
}

void	choose_sorting(int argc, t_list **stack_a, t_list **stack_b)
{
	int	flag;

	flag = 0;
	if (argc == 3 && flag == 0)
		swap(stack_a, 'a');
	if (argc == 4)
	{
		while (flag == 0)
		{
			sort_three(stack_a);
			flag = check_sorted(stack_a);
		}
	}
	else if (argc == 6)
		sort_five(stack_a, stack_b);
	else if (argc > 6)
		sort_hundreds(stack_a, stack_b);
}

void	pivoting(t_list **stack_a, t_list **stack_b)
{
	t_atb	seq_head;
	int		round;
	int		size_a;

	seq_head = sequence_finder(*stack_a, 1);
	size_a = lstsize(*stack_a);
	if (seq_head.x > 3)
		push_many(stack_a, stack_b, size_a);
	else
	{
		round = 1;
		while (round <= PIVOT)
		{
			round = pivot_without_seq(stack_a, stack_b, size_a, round);
			if (lstsize(*stack_a) == 3)
				break ;
		}
		while (check_sorted(stack_a) == 0)
			sort_three(stack_a);
	}
	return ;
}

t_atb	update_seq(t_atb seq, int i, int value)
{
	if (i > seq.x)
	{
		seq.x = i;
		seq.y = value;
		return (seq);
	}
	else
		return (seq);
}

void	move_seq(t_atb seq, t_list **stack_a, t_list **stack_b,
				int size_a)
{
	int	i;
	int	round;
	int	tail;

	i = lstsize(*stack_a) - seq.x;
	round = check_next(*stack_a, seq, 1, size_a);
	tail = get_tail(*stack_a, seq);
	while (i--)
	{
		if (lstsize(*stack_a) == seq.x + 1
			&& (*stack_a)->next->value == seq.y)
			push(stack_a, stack_b, 'b');
		if ((*stack_a)->rank == tail)
			break ;
		if ((*stack_a)->rank > (size_a * round) / PIVOT
			|| (*stack_a)->value == seq.y)
			reverse_rotate(stack_a, 'a');
		if ((*stack_a)->rank <= (size_a * round) / PIVOT)
			push(stack_a, stack_b, 'b');
	}
	return ;
}
