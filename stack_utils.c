/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:46:30 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/02 17:34:41 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_el(t_list *stack)
{
	int	i;

	i = 0;
	go_to_first_el(&stack);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	return (i + 1);
}

void	go_to_first_el(t_list **stack)
{
	if (*stack)
	{
		while ((*stack)->prec)
			(*stack) = (*stack)->prec;
	}
}

void	go_to_last_el(t_list **stack)
{
	if (*stack)
	{
		while ((*stack)->next)
			(*stack) = (*stack)->next;
	}
}

void	free_stack(t_list *stack)
{
	t_list	*tmp;

	tmp = NULL;
	if (stack)
	{
		while (stack->prec)
			stack = stack->prec;
		while (stack->next)
		{
			tmp = stack->next;
			ft_lst_delone(stack);
			stack = tmp;
		}
		ft_lst_delone(stack);
	}
}
