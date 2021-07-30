/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:13:05 by clde-ber          #+#    #+#             */
/*   Updated: 2021/07/29 19:20:39 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
sa :swap a- intervertit les 2 premiers éléments au sommet de la pile a. Ne fait rien s’il n’y en a qu’un ou aucun.
sb :swap b- intervertit les 2 premiers éléments au sommet de la pile b. Ne fait rien s’il n’y en a qu’un ou aucun.
ss :saetsben même temps.pa :push a- prend le premier élément au sommet de b et le met sur a. Ne fait rien si b est vide.
pb :push b- prend le premier élément au sommet de a et le met sur b. Ne fait rien si a est vide.
ra :rotate a- décale d’une position vers le haut tous les élements de la pile a. Le premier élément devient le dernier.
rb :rotate b- décale d’une position vers le haut tous les élements de la pile b. Le premier élément devient le dernier.
rr :raetrben même temps.rra :reverse rotate a- décale d’une position vers le bas tous les élements dela pile a. Le dernier élément devient le premier.
rrb :reverse rotate b- décale d’une position vers le bas tous les élements dela pile b. Le dernier élément devient le premier.
rrr :rra et rrb en même temps
*/

#include "push_swap.h"

void    ft_pb(t_list **stack_a, t_list **stack_b, t_list **cmd)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    go_to_first_el(stack_a);
    tmp2 = (*stack_a)->next;
    tmp = *stack_a;
    if (tmp->next)
        tmp->next->prec = 0;
    if (!(*stack_b))
    {
        ft_lst_addback(stack_b, tmp);
    }
    else
    {
        go_to_first_el(stack_b);
        tmp3 = *stack_b;
        ft_lst_addfront(stack_b, tmp);
        (*stack_b)->prec = 0;
        (*stack_b)->next = tmp3;
        tmp3->prec = *stack_b;
    }
    *stack_a = tmp2;
    ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("pb")));
}

void    ft_pa(t_list **stack_a, t_list **stack_b, t_list **cmd)
{
    t_list *tmp;
    t_list *tmp2;
    t_list *tmp3;

    go_to_first_el(stack_b);
    tmp2 = (*stack_b)->next;
    tmp = *stack_b;
    if (tmp->next)
        tmp->next->prec = 0;
    if (!(*stack_a))
    {
        ft_lst_addback(stack_a, tmp);
    }
    else
    {
        go_to_first_el(stack_a);
        tmp3 = *stack_a;
        ft_lst_addfront(stack_a, tmp);
        (*stack_a)->next = tmp3;
        (*stack_a)->prec = 0;
        tmp3->prec = *stack_a;
    }
    *stack_b = tmp2;
    ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("pa")));
}

void    ft_ra(t_list *stack, t_list **cmd)
{
    t_list *tmp;

    tmp = NULL;
    if (count_el(stack) > 2)
    {
        go_to_last_el(&stack);
        tmp = stack;
        go_to_first_el(&stack);
        stack->next->prec = 0;
        stack->prec = tmp;
        tmp->next = stack;
        stack->next = 0;
    }
    else
        ft_sa(stack, cmd);
    ft_lst_addback(cmd, ft_lstnew(ft_strdup("ra")));
}

void    ft_rb(t_list *stack, t_list **cmd)
{
    t_list *tmp;

    tmp = NULL;
    if (count_el(stack) > 2)
    {
        go_to_last_el(&stack);
        tmp = stack;
        go_to_first_el(&stack);
        stack->next->prec = 0;
        stack->prec = tmp;
        tmp->next = stack;
        stack->next = 0;
    }
    else
        ft_sb(stack, cmd);
    ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rb")));
}


void    ft_rra(t_list *stack, t_list **cmd)
{
    t_list *tmp;

    tmp = NULL;
    if (count_el(stack) > 2)
    {
        go_to_first_el(&stack);
        tmp = stack;
        go_to_last_el(&stack);
        stack->prec->next = 0;
        stack->next = tmp;
        tmp->prec = stack;
        stack->prec = 0;
    }
    else
        ft_sa(stack, cmd);
    ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rra")));
}

void    ft_rrb(t_list *stack, t_list **cmd)
{
    t_list *tmp;

    tmp = NULL;
    if (count_el(stack) > 2)
    {
        go_to_first_el(&stack);
        tmp = stack;
        go_to_last_el(&stack);
        stack->prec->next = 0;
        stack->next = tmp;
        tmp->prec = stack;
        stack->prec = 0;
    }
    else
        ft_sb(stack, cmd);
    ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rrb")));
}

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    ft_sa(t_list *stack, t_list **cmd)
{
    go_to_last_el(&stack);
    if (count_el(stack) > 1)
    {
        ft_swap(stack->prec->value, stack->value);
    }
    ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sa")));
}

void    ft_sb(t_list *stack, t_list **cmd)
{
    go_to_last_el(&stack);
    if (count_el(stack) > 1)
    {
        ft_swap(stack->prec->value, stack->value);
    }
    ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sb")));
}