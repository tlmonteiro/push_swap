/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:52:48 by marvin            #+#    #+#             */
/*   Updated: 2023/02/02 13:06:04 by tlemos-m         ###   ########.fr       */
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
	struct s_list	*prev;
	int				value;
	int				rank;
	struct s_list	*next;
}					t_list;

int				main(int argc, char **argv);
t_list			*parse_arg(char **argv, int argc);
void			initialize_stack(t_list **stack_a, int value);
void			free_stack(t_list **stack);
int				check_doubles(char **argv);
int				check_input(char *nptr);
t_list			*ps_lstnew(int value);
t_list			*ps_lstlast(t_list *stack);
void			ps_lstadd_front(t_list **stack, t_list *node);
void			ps_lstadd_back(t_list **stack, t_list *node);
int				ps_lstsize(t_list *stack);
void			get_rank(t_list *stack);
int				update_rank(t_list *temp, t_list *node, int rank);
int				check_sorted(t_list **stack);
int				check_min_moves(t_list **stack);
int				moves_to_top(t_list *stack);
int				ft_isdigit(int c);
long long		ft_atoll(const char *nptr);
int				ft_atoi(const char *nptr);
void			push_swap(t_list **stack);
void			swap(t_list **stack, char letter);
void			push_a(t_list **stack_a, t_list **stack_b);
void			push_b(t_list **stack_a, t_list **stack_b);
void			rotate(t_list **stack, char letter);
void			reverse_rotate(t_list **stack, char letter);
void			double_swap(t_list **stack_a, t_list **stack_b);
void			double_rotate(t_list **stack_a, t_list **stack_b);
void			double_reverse_rotate(t_list **stack_a, t_list **stack_b);
void			print_stack(t_list **stack_a, char letter);

#endif