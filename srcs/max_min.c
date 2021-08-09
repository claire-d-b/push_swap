/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_min.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:47:42 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/05 11:50:44 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

int	index_max_el(t_list **stack, int max)
{
	int	i;

	i = 0;
	if (*stack)
	{
		go_to_first_el(stack);
		while ((*stack)->next)
		{
			if (*(int *)(*stack)->value == max)
				return (i);
			*stack = (*stack)->next;
			i++;
		}
		go_to_first_el(stack);
	}
	return (i);
}

int	find_max(t_list *max)
{
	int	max_value;

	go_to_first_el(&max);
	max_value = *(int *)max->value;
	while (max->next)
	{
		if (max_value < *(int *)max->value)
			max_value = *(int *)max->value;
		max = max->next;
	}
	if (max_value < *(int *)max->value)
		max_value = *(int *)max->value;
	go_to_first_el(&max);
	return (max_value);
}

int	find_min(t_list *max)
{
	int	max_value;

	go_to_first_el(&max);
	max_value = *(int *)max->value;
	while (max->next)
	{
		if (max_value > *(int *)max->value)
			max_value = *(int *)max->value;
		max = max->next;
	}
	if (max_value > *(int *)max->value)
		max_value = *(int *)max->value;
	go_to_first_el(&max);
	return (max_value);
}

void	set_ct_limit(int *ct, t_list **stack_a, t_list *stack_b, t_count *count)
{
	if (*ct == -1 && *(int *)(*stack_a)->value > find_max(stack_b))
		*ct = index_max_el(&stack_b, find_max(stack_b));
	else if (*ct == -1 && *(int *)(*stack_a)->value < find_min(stack_b))
		*ct = index_max_el(&stack_b, find_min(stack_b)) + 1;
	if (*ct > count->stack_b_nb / 2)
		*ct = count->stack_b_nb - *ct;
}
