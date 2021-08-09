/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:37:40 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/05 16:30:06 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

void	ft_rr_utils(t_list *stack)
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
	}
	else
	{
		go_to_last_el(&stack);
		if (count_el(stack) > 1)
		{
			ft_swap(stack->prec->value, stack->value);
		}
	}
}

void	ft_rr(t_list *stack_a, t_list *stack_b, t_list **cmd)
{
	ft_rr_utils(stack_a);
	ft_rr_utils(stack_b);
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

void	ft_rrr_utils(t_list *stack)
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
	}
	else
	{
		go_to_last_el(&stack);
		if (count_el(stack) > 1)
		{
			ft_swap(stack->prec->value, stack->value);
		}
	}
}

void	ft_rrr(t_list *stack_a, t_list *stack_b, t_list **cmd)
{
	ft_rrr_utils(stack_a);
	ft_rrr_utils(stack_b);
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
