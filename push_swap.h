/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:52:48 by marvin            #+#    #+#             */
/*   Updated: 2023/01/13 10:31:41 by tlemos-m         ###   ########.fr       */
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
	int				*value;
	int				*rank;
	struct s_list	*next;
}					t_list;

int				main(int argc, char **argv);
t_list			**parse_arg(char **argv, int argc);
void			free_stack(t_list **stack);
long int		check_input(const char *nptr);
t_list			*ps_lstnew(long int value);
t_list			*ps_lstlast(t_list *stack);
void			ps_lstadd_back(t_list **stack, t_list *node);
int				ft_isdigit(int c);
long int		ft_atoli(const char *nptr);
void			push_swap(t_list **stack);
void			swap(t_list **stack);
void			push(t_list **stack);
void			rotate(t_list **stack);

#endif