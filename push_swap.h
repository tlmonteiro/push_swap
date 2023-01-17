/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:52:48 by marvin            #+#    #+#             */
/*   Updated: 2023/01/13 13:06:49 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

typedef struct s_list
{
	long long		value;
	int				rank;
	struct s_list	*next;
}					t_list;

int				main(int argc, char **argv);
t_list			**parse_arg(char **argv);
void			initialize_stack(t_list **stack_a, long long value);
void			free_stack(t_list **stack);
int				check_doubles(char **argv);
int				check_input(char *nptr);
t_list			*ps_lstnew(long long value);
t_list			*ps_lstlast(t_list *stack);
void			ps_lstadd_back(t_list **stack, t_list *node);
int				ps_lstsize(t_list *stack);
int				ft_isdigit(int c);
long long		ft_atoll(const char *nptr);
void			push_swap(t_list **stack);
void			swap(t_list **stack);
void			push(t_list **stack);
void			rotate(t_list **stack);

#endif