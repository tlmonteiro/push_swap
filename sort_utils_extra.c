/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:28:38 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/07 22:09:14 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_same(t_list **stk_a, int mv_a, t_list **stk_b, int mv_b)
{
	if (mv_a <= 0)
	{
		while (mv_a++ != 0 && mv_b++ != 0)
			double_reverse_rotate(stk_a, stk_b);
		while (mv_a++ != 0)
			reverse_rotate(stk_a, 'a');
		while (mv_b++ != 0)
			reverse_rotate(stk_b, 'b');
	}
	else
	{
		while (mv_a-- != 0 && mv_b-- != 0)
			double_rotate(stk_a, stk_b);
		while (mv_a-- != 0)
			rotate(stk_a, 'a');
		while (mv_b-- != 0)
			rotate(stk_b, 'b');
	}
	return ;
}

void	push_opposites(t_list **stk_a, int mv_a, t_list **stk_b, int mv_b)
{
	if (mv_a < 0)
	{
		while (mv_a++ != 0)
			reverse_rotate(stk_a, 'a');
	}
	else if (mv_a > 0)
	{
		while (mv_a-- != 0)
			rotate(stk_a, 'a');
	}
	if (mv_b < 0)
	{
		while (mv_b++ != 0)
			reverse_rotate(stk_b, 'b');
	}
	else if (mv_b > 0)
	{
		while (mv_b-- != 0)
			rotate(stk_b, 'b');
	}
	return ;
}
