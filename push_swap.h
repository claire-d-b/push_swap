/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:18:01 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/02 12:28:16 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prec;
	void			*value;
}			t_list;

typedef struct s_count
{
	int	count;
	int	stack_a_nb;
	int	stack_b_nb;
	int	r_or_rr;
	int	stack_a_idx;
	int	stack_b_idx;
	int	start_nb;
	int	real_index_b;
}			t_count;

/*
** combine
*/
void	ft_rr_utils(t_list *stack);
void	ft_rr(t_list *stack_a, t_list *stack_b, t_list **cmd);
void	ft_rrr_utils(t_list *stack);
void	ft_rrr(t_list *stack_a, t_list *stack_b, t_list **cmd);

/*
** find_sort_style
*/
int		find_index(int value, t_list *stack);
void	set_if_high_or_low(int i, int *k, int *boolean, t_count *count);
void	choose_value(t_list **stack_a, t_list *stack_b, t_count *count);

/*
** init
*/
void	init_four_values(int *i, int *k, int *boolean, int *ct);
int		init_stacks(t_list **stack_a, t_list **stack_b);
void	init_struct_count(t_count *count, int args_nb);

/*
** list
*/
t_list	*ft_lstnew(void *value);
void	ft_lst_delone(t_list *el);
void	ft_lst_addback(t_list **stack, t_list *el);
void	ft_lst_addfront(t_list **stack, t_list *el);

/*
** max_min
*/
int		index_max_el(t_list **stack, int max);
int		find_max(t_list *max);
int		find_min(t_list *max);
void	set_ct_limit(int *ct, t_list **stack_a, t_list *stack_b, \
t_count *count);

/*
** print
*/
void	print_commands(t_list **cmd);
void	print_count(t_list **cmd);
void	print_no_details(t_list *stack_a, t_list *stack_b);
void	print_stack_a_a_b(t_list *stack_a, t_list *stack_b);

/*
** push_swap
*/
int		checker(t_list *s_lst);
void	push_swap(t_list **stack_a, t_list **stack_b, int nb, t_list **cmd);

/*
** push
*/
void	ft_pb(t_list **stack_a, t_list **stack_b, t_list **cmd);
void	ft_pa(t_list **stack_a, t_list **stack_b, t_list **cmd);

/*
** rotate
*/
void	ft_ra(t_list *stack, t_list **cmd);
void	ft_rb(t_list *stack, t_list **cmd);
void	ft_rra(t_list *stack, t_list **cmd);
void	ft_rrb(t_list *stack, t_list **cmd);

/*
** sort_utils
*/
void	high_limit(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd);
void	low_limit(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd);
void	high_insert(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd);
void	low_insert(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd);

/*
** sort
*/
void	last_sort(t_list **stack_b, t_count *count, t_list **cmd);
void	set_index_limit(t_list **stack_a, t_list **stack_b, t_count *count);
void	handle_limits(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd);
void	sort(t_list **stack_a, t_list **stack_b, t_count *count, t_list **cmd);

/*
** stack_utils
*/
int		count_el(t_list *stack);
void	go_to_first_el(t_list **stack);
void	go_to_last_el(t_list **stack);
void	free_stack(t_list *stack);

/*
** swap
*/
void	ft_swap(int *a, int *b);
void	ft_ss(t_list *stack_a, t_list *stack_b);
void	ft_sa(t_list *stack);
void	ft_sb(t_list *stack);

/*
** utils
*/
int		ft_strlen(char *str);
char	*ft_strdup(char *str);
int		ft_isdigit(char c);
int		ft_atoi(const char *str);

#endif