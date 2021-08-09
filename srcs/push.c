/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:36:18 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/09 18:27:08 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

void	ft_pb(t_list **stack_a, t_list **stack_b, t_list **cmd)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

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

void	ft_pa(t_list **stack_a, t_list **stack_b, t_list **cmd)
{
	t_list	*tmp;
	t_list	*tmp2;
	t_list	*tmp3;

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
