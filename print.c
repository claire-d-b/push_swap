/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:44:38 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/02 12:12:00 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(t_list **cmd)
{
    while ((*cmd)->next)
    {
        printf("cmd %s\n", (char *)(*cmd)->value);
        *cmd = (*cmd)->next;
    }
    printf("cmd %s\n", (char *)(*cmd)->value);
}

void	print_count(t_list **cmd)
{
    int i;

    i = 0;
    go_to_first_el(cmd);
    while ((*cmd)->next)
    {
        *cmd = (*cmd)->next;
        i++;
    }
    printf("count %d\n", i);
}

void	print_no_details(t_list *stack_a, t_list *stack_b)
{
    if (stack_a)
    {
        while (stack_a->prec)
        stack_a = stack_a->prec;
        while (stack_a->next)
        {
            printf("stack a v %d\n", *(int *)stack_a->value);
            stack_a = stack_a->next;
        }
        printf("stack a v %d\n", *(int *)stack_a->value);
    }
    if (stack_b)
    {
        while (stack_b->prec)
            stack_b = stack_b->prec;
        while (stack_b->next)
        {
            printf("stack b v %d\n", *(int *)stack_b->value);
            stack_b = stack_b->next;
        }
        printf("stack b v %d\n", *(int *)stack_b->value);
    }
}

void	print_stack_a_a_b(t_list *stack_a, t_list *stack_b)
{
    if (stack_a)
    {
        while (stack_a->prec)
        stack_a = stack_a->prec;
        while (stack_a->next)
        {
            printf("stack a v %d\n", *(int*)stack_a->value);
            printf("stack a %d\n", (int)stack_a);
            printf("stack a next %d\n", (int)stack_a->next);
            printf("stack a prec %d\n", (int)stack_a->prec);
            stack_a = stack_a->next;
        }
        printf("stack a v %d\n", *(int*)stack_a->value);
        printf("stack a %d\n", (int)stack_a);
        printf("stack a next %d\n", (int)stack_a->next);
        printf("stack a prec %d\n", (int)stack_a->prec);
    }
    if (stack_b)
    {
        while (stack_b->prec)
            stack_b = stack_b->prec;
        while (stack_b->next)
        {
            printf("stack b v %d\n", *(int*)stack_b->value);
            printf("stack b %d\n", (int)stack_b);
            printf("stack b next %d\n", (int)stack_b->next);
            printf("stack b prec %d\n", (int)stack_b->prec);
            stack_b = stack_b->next;
        }
        printf("stack b v %d\n", *(int*)stack_b->value);
        printf("stack b %d\n", (int)stack_b);
        printf("stack b next %d\n", (int)stack_b->next);
        printf("stack b prec %d\n", (int)stack_b->prec);
    }
}
