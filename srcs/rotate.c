/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:36:44 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/05 16:29:38 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_list *stack, t_list **cmd)
{
	t_list	*tmp;

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
		ft_sa(stack);
		ft_lst_addback(cmd, ft_lstnew(ft_strdup("sa")));
	}
}

void	ft_rb(t_list *stack, t_list **cmd)
{
	t_list	*tmp;

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
		ft_sb(stack);
		ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sb")));
	}
}

void	ft_rra(t_list *stack, t_list **cmd)
{
	t_list	*tmp;

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
		ft_sa(stack);
		ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sa")));
	}
}

void	ft_rrb(t_list *stack, t_list **cmd)
{
	t_list	*tmp;

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
		ft_sb(stack);
		ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sb")));
	}
}
