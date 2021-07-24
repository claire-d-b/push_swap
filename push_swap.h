/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:18:01 by clde-ber          #+#    #+#             */
/*   Updated: 2021/07/23 15:55:04 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
    struct s_list *next;
    struct s_list *prec;
    int value;
}           t_list;

t_list	*ft_lstnew(int value);
void    ft_lst_delone(t_list *el);
int     init_stacks(t_list **stack_a, t_list **stack_b);
void    fill_list(t_list *stack_a, char *arg);
void    ft_lst_addback(t_list **stack, t_list *el);
void    ft_lst_addfront(t_list **stack, t_list *el);
void    go_to_first_el(t_list **stack);
void    go_to_last_el(t_list **stack);
void    push_swap(t_list **stack_a, t_list **stack_b, int nb);
void    ft_pb(t_list **stack_a, t_list **stack_b);
void    ft_pa(t_list **stack_a, t_list **stack_b);
int     count_el(t_list *stack);
void    ft_ra_or_rb(t_list *stack);
void    ft_rra_or_rrb(t_list *stack);
void    ft_sa_or_sb(t_list *stack);
void    ft_swap(int *a, int *b);
int     is_tb_rotated(t_list *stack);
int     is_tb_rrotated(t_list *stack);
int     is_tb_swapped(t_list *stack);

#endif