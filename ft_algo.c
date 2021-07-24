/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 15:40:41 by clde-ber          #+#    #+#             */
/*   Updated: 2021/07/23 17:21:28 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int which_index_tbs(int value, t_list *stack)
{
    int i;

    i = 0;
    if (stack)
    {
        go_to_first_el(&stack);
        while (stack->next)
        {
            if (value < stack->value)
                return (i);
            i++;
            stack = stack->next;
        }
    }
    return (i);
}

int find_el(int value, t_list *stack)
{
    int i;

    i = 0;
    if (stack)
    {
        while (stack->next)
        {
            if (value == stack->value)
                return (i);
            i++;
        }
    }
    return (i);
}

int is_tb_rotated(t_list *stack)
{
    t_list *tmp;
    
    tmp = NULL;
    if (!stack)
        return (-1);
    go_to_last_el(&stack);
    tmp = stack;
    if (!stack->prec)
        return (-1);
    go_to_first_el(&stack);
    if (stack->value > tmp->value)
        return (1);
    return (0);
}

int is_tb_rrotated(t_list *stack)
{
    t_list *tmp;
    
    tmp = NULL;
    if (!stack)
        return (-1);
    go_to_first_el(&stack);
    tmp = stack;
    if (!stack->next)
        return (-1);
    go_to_last_el(&stack);
    if (stack->value < tmp->value)
        return (1);
    return (0);
}

int is_tb_swapped(t_list *stack)
{
    if (!stack)
        return (-1);
    go_to_last_el(&stack);
    if (!stack->prec)
        return (-1);
    if (stack->value < stack->prec->value)
        return (1);
    return (0);
}
