/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:18:01 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/02 11:04:19 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
typedef struct s_chain
{
    void *content;
    struct s_chain  *next;
}

typedef struct s_group
{
    int info;
    char *data;
}

t_group *lala;

lala = malloc



t_chain stack_a;

stack_a.content = lala;

int *num;

num = malloc (sizeof(int));
*num = 5;

stack_a.content = num;

printf("%d", *(int*)stack_a.content);


char *cmd;

cmd = strdup("salut claire");
stack_a.content = cmd;

*/

typedef struct s_list
{
    struct s_list   *next;
    struct s_list   *prec;
    void            *value;
}           t_list;

typedef struct s_count
{
    int count;
    int stack_a_nb;
    int stack_b_nb;
    int r_or_rr;
    int stack_a_idx;
    int stack_b_idx;
    int start_nb;
    int real_index_b;
}           t_count;

void    print_no_details(t_list *stack_a, t_list *stack_b);
t_list	*ft_lstnew(void *value);
void    ft_lst_delone(t_list *el);
int     init_stacks(t_list **stack_a, t_list **stack_b);
void    fill_list(t_list *stack_a, char *arg);
void    ft_lst_addback(t_list **stack, t_list *el);
void    ft_lst_addfront(t_list **stack, t_list *el);
void    go_to_first_el(t_list **stack);
void    go_to_last_el(t_list **stack);
void    push_swap(t_list **stack_a, t_list **stack_b, int nb, t_list **cmd);
void    ft_pb(t_list **stack_a, t_list **stack_b, t_list **cmd);
void    ft_pa(t_list **stack_a, t_list **stack_b, t_list **cmd);
int     count_el(t_list *stack);
void    ft_ra(t_list *stack, t_list **cmd);
void    ft_rb(t_list *stack, t_list **cmd);
void    ft_rra(t_list *stack, t_list **cmd);
void    ft_rrb(t_list *stack, t_list **cmd);
void    ft_sa(t_list *stack, t_list **cmd);
void    ft_sb(t_list *stack, t_list **cmd);
void    ft_swap(int *a, int *b);
int     is_tb_rotated(t_list *stack);
int     is_tb_rrotated(t_list *stack);
int     is_tb_swapped(t_list *stack);
char    *ft_strdup(char *str);
int     ft_strlen(char *str);
void    ft_rr(t_list *stack_a, t_list *stack_b, t_list **cmd);
void    ft_rrr(t_list *stack_a, t_list *stack_b, t_list **cmd);
void    ft_ss(t_list *stack_a, t_list *stack_b, t_list **cmd);

#endif