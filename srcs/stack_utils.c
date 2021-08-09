/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:46:30 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/09 19:21:20 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "/includes/push_swap.h"

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
	go_to_first_el(&stack);
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
