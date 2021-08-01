/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:13:05 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/01 19:38:51 by clde-ber         ###   ########.fr       */
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

void    ft_rr(t_list *stack_a, t_list *stack_b, t_list **cmd)
{
    t_list *tmp;

    tmp = NULL;
    if (count_el(stack_a) > 2)
    {
        go_to_last_el(&stack_a);
        tmp = stack_a;
        go_to_first_el(&stack_a);
        stack_a->next->prec = 0;
        stack_a->prec = tmp;
        tmp->next = stack_a;
        stack_a->next = 0;
    }
    else
    {
        go_to_last_el(&stack_a);
        if (count_el(stack_a) > 1)
        {
            ft_swap(stack_a->prec->value, stack_a->value);
        }
    }
    if (count_el(stack_b) > 2)
    {
        go_to_last_el(&stack_b);
        tmp = stack_b;
        go_to_first_el(&stack_b);
        stack_b->next->prec = 0;
        stack_b->prec = tmp;
        tmp->next = stack_b;
        stack_b->next = 0;
    }
    else
    {
        go_to_last_el(&stack_b);
        if (count_el(stack_b) > 1)
        {
            ft_swap(stack_b->prec->value, stack_b->value);
        }
    }
    if (count_el(stack_a) > 2 && count_el(stack_b) > 2)
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rr")));
    else if (count_el(stack_a) > 2)
    {
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("ra")));
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sb")));
    }
    else if (count_el(stack_b) > 2)
    {
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rb")));
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sa")));
    }
    else
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("ss")));  
}

void    ft_rrr(t_list *stack_a, t_list *stack_b, t_list **cmd)
{
    t_list *tmp;
    
    tmp = NULL;
    if (count_el(stack_a) > 2)
    {
        go_to_first_el(&stack_a);
        tmp = stack_a;
        go_to_last_el(&stack_a);
        stack_a->prec->next = 0;
        stack_a->next = tmp;
        tmp->prec = stack_a;
        stack_a->prec = 0;
    }
    else
    {
        go_to_last_el(&stack_a);
        if (count_el(stack_a) > 1)
        {
            ft_swap(stack_a->prec->value, stack_a->value);
        }
    }
    if (count_el(stack_b) > 2)
    {
        go_to_first_el(&stack_b);
        tmp = stack_b;
        go_to_last_el(&stack_b);
        stack_b->prec->next = 0;
        stack_b->next = tmp;
        tmp->prec = stack_b;
        stack_b->prec = 0;
    }
    else
    {
        go_to_last_el(&stack_b);
        if (count_el(stack_b) > 1)
        {
            ft_swap(stack_b->prec->value, stack_b->value);
        }
    }
    if (count_el(stack_a) > 2 && count_el(stack_b) > 2)
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rrr")));
    else if (count_el(stack_a) > 2)
    {
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rra")));
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sb")));
    }
    else if (count_el(stack_b) > 2)
    {
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rrb")));
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sa")));
    }
    else
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("ss")));
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
        ft_lst_addback(cmd, ft_lstnew(ft_strdup("ra")));
    }
    else
    {
        ft_sa(stack, cmd);
        ft_lst_addback(cmd, ft_lstnew(ft_strdup("sa")));
    }
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
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rb")));
    }
    else
    {
        ft_sb(stack, cmd);
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sb")));
    }
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
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rra")));
    }
    else
    {
        ft_sa(stack, cmd);
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sa")));
    }
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
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("rrb")));
    }
    else
    {
        ft_sb(stack, cmd);
        ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sb")));
    }
}

void    ft_swap(int *a, int *b)
{
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void    ft_ss(t_list *stack_a, t_list *stack_b, t_list **cmd)
{
    (void)cmd;
    ft_sa(stack_a, cmd);
    ft_sb(stack_b, cmd);
}

void    ft_sa(t_list *stack, t_list **cmd)
{
    (void)cmd;
    go_to_last_el(&stack);
    if (count_el(stack) > 1)
        ft_swap(stack->prec->value, stack->value);
}

void    ft_sb(t_list *stack, t_list **cmd)
{
    (void)cmd;
    go_to_last_el(&stack);
    if (count_el(stack) > 1)
        ft_swap(stack->prec->value, stack->value);
}