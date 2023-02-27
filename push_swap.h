/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemos-m <tlemos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:52:48 by marvin            #+#    #+#             */
/*   Updated: 2023/02/27 11:45:43 by tlemos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# ifndef PIVOT
#  define PIVOT 3
# endif

typedef struct s_list
{
	struct s_list	*prev;
	int				value;
	int				rank;
	struct s_list	*next;
}					t_list;

int				main(int argc, char **argv);
t_list			*parse_arg(t_list *stack, char **argv, int argc);
void			initialize_stack(t_list **stack_a, int value);
void			free_stack(t_list **stack);
int				check_doubles(char **argv);
int				check_input(char *nptr);
t_list			*lstnew(int value);
t_list			*lstlast(t_list *stack);
void			lstadd_front(t_list **stack, t_list *node);
void			lstadd_back(t_list **stack, t_list *node);
int				lstsize(t_list *stack);
void			get_rank(t_list *stack);
int				check_sorted(t_list **stack);
void			check_to_pull(t_list **stack_a, t_list **stack_b);
void			check_to_push(t_list **stack_a, char letter, int pivot);
int				put_in_place(t_list **stack, char letter, int counter);
int				count_moves(int rank, t_list *stack);
int				ft_isdigit(int c);
long long		ft_atoll(const char *nptr);
int				ft_atoi(const char *nptr);
void			push_swap(char **argv, int argc);
void			choose_sorting(int argc, t_list **stack_a, t_list **stack_b);
void			swap(t_list **stack, char letter);
void			push(t_list **src, t_list **dest, char letter);
void			rotate(t_list **stack, char letter);
void			reverse_rotate(t_list **stack, char letter);
void			double_swap(t_list **stack_a, t_list **stack_b);
void			double_rotate(t_list **stack_a, t_list **stack_b);
void			double_reverse_rotate(t_list **stack_a, t_list **stack_b);
void			print_stack(t_list **stack, char letter);
void			sort_three(t_list **stack);
void			sort_five(t_list **stack_a, t_list **stack_b);
void			sort_hundreds(t_list **stack_a, t_list **stack_b);
void			pivoting(t_list **stack_a, t_list **stack_b, int size);

#endif