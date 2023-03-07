/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:28:38 by tlemos-m          #+#    #+#             */
/*   Updated: 2023/03/07 16:29:36 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	big_push(t_list **stack_a, t_list **stack_b, int moves_a, int moves_b)
{
	if (moves_a && moves_b < 0)
	{
		if (moves_a <= moves_b)
		{
			while (moves_b++)
			{
				double_reverse_rotate(stack_a, stack_b);
				moves_a++;
			}
			while (moves_a != 0)
				reverse_rotate(stack_a, 'a');
		}
	}
	else if (moves_a && moves_b > 0)
	{
		if (moves_a <= moves_b)
		{
			while (moves_a--)
			{
				double_rotate(stack_a, stack_b);
				moves_b--;
			}
			while (moves_b-- != 0)
				rotate(stack_b, 'b');
		}
	}
	else
	{
		if (moves_a < 0)
		{
			while (moves_a++)
				reverse_rotate(stack_a, 'a');
		}
		else 
		{
			while (moves_a--)
				rotate(stack_a, 'a');
		}
		if (moves_b < 0)
		{
			while (moves_b++)
				reverse_rotate(stack_b, 'b');
		}
		else 
		{
			while (moves_b--)
				rotate(stack_b, 'b');
		}
	}
}

void    push_opposite()