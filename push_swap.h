/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:52:48 by marvin            #+#    #+#             */
/*   Updated: 2023/01/11 16:41:33 by tlemos-m         ###   ########.fr       */
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
char			*check_input(const char *nptr);
t_list			*ps_lstnew(struct s_list **stack, int value, int rank);
t_list			*ps_lstlast(t_list *stack);
void			ps_lstadd_back(t_list **stack, t_list *node);
int				ft_isdigit(int c);
long int		ft_atoi(const char *nptr);
void			push_swap(t_list **stack);
void			swap(t_list **stack);
void			push(t_list **stack);
void			rotate(t_list **stack);

#endif