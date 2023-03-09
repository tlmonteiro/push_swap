/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:28:38 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/09 14:02:16 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_and_update(t_list **stk_a, t_list **stk_b, t_list *hd_a,
			int size);

void	pivot_with_seq(t_atb seq, t_list **stack_a, t_list **stack_b)
{
	int	i;
	int	size_a;

	size_a = lstsize(*stack_a);
	i = size_a - seq.x;
	if (seq.x <= (size_a / 2))
	{
		while (seq.x-- > 0)
			rotate(stack_a, 'a');
	}
	else
	{
		while (i--)
		{
			reverse_rotate(stack_a, 'a');
			push(stack_a, stack_b, 'b');
		}
	}
}

int	pivot_without_seq(t_list **stack_a, t_list **stk_b, int i)
{
	int		size_a;
	t_list	*head_a;

	size_a = lstsize(*stack_a);
	head_a = *stack_a;
	while (*stack_a)
	{
		while ((*stack_a)->rank <= (size_a / PIVOT) * i)
			push_and_update(stack_a, stk_b, head_a, size_a);
		while ((*stack_a)->rank > (size_a / PIVOT) * i)
		{
			head_a = *stack_a;
			rotate(stack_a, 'a');
			print_stack(stack_a, 'a');
			print_stack(stk_b, 'b');
			if (*stack_a == head_a)
				break ;
		}
		if (*stack_a == head_a || lstsize(*stack_a) == 3)
			break ;
	}
	i++;
	return (i);
}

void	push_and_update(t_list **stk_a, t_list **stk_b, t_list *hd_a, int size)
{
	if ((*stk_a)->rank < (size - 2))
	{
		push(stk_a, stk_b, 'b');
		if (lstsize(*stk_b) < 1)
			hd_a = *stk_a;
	}
	return ;
}

void	push_same(t_list **stk_a, int mv_a, t_list **stk_b, int mv_b)
{
	if (mv_a <= 0)
	{
		while (mv_a++ < 0 && mv_b++ < 0)
			double_reverse_rotate(stk_a, stk_b);
		while (mv_a++ <= 0)
			reverse_rotate(stk_a, 'a');
		while (mv_b++ <= 0)
			reverse_rotate(stk_b, 'b');
	}
	else
	{
		while (mv_a-- > 0 && mv_b-- > 0)
			double_rotate(stk_a, stk_b);
		while (mv_a-- > 0)
			rotate(stk_a, 'a');
		while (mv_b-- > 0)
			rotate(stk_b, 'b');
	}
	return ;
}

void	push_opposites(t_list **stk_a, int mv_a, t_list **stk_b, int mv_b)
{
	if (mv_a < 0)
	{
		while (mv_a++ < 0)
			reverse_rotate(stk_a, 'a');
	}
	else if (mv_a > 0)
	{
		while (mv_a-- > 0)
			rotate(stk_a, 'a');
	}
	if (mv_b < 0)
	{
		while (mv_b++ < 0)
			reverse_rotate(stk_b, 'b');
	}
	else if (mv_b > 0)
	{
		while (mv_b-- > 0)
			rotate(stk_b, 'b');
	}
	return ;
}
