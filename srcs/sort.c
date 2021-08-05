/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:51:26 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/05 11:51:11 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	last_sort(t_list **stack_b, t_count *count, t_list **cmd)
{
	go_to_first_el(stack_b);
	count->stack_b_idx = index_max_el(stack_b, find_min(*stack_b)) + 1;
	if (count->stack_b_idx <= count->stack_b_nb / 2)
	{
		while (count->stack_b_idx > 0)
		{
			ft_rb(*stack_b, cmd);
			go_to_first_el(stack_b);
			count->stack_b_idx--;
		}
	}
	else
	{
		while (count->stack_b_idx < count->stack_b_nb)
		{
			ft_rrb(*stack_b, cmd);
			go_to_first_el(stack_b);
			count->stack_b_idx++;
		}
	}
}

void	set_index_limit(t_list **stack_a, t_list **stack_b, t_count *count)
{
	go_to_first_el(stack_b);
	go_to_first_el(stack_a);
	if (*(int *)(*stack_a)->value > find_max(*stack_b))
		count->stack_b_idx = index_max_el(stack_b, find_max(*stack_b));
	else
		count->stack_b_idx = index_max_el(stack_b, find_min(*stack_b)) + 1;
}

void	handle_limits(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd)
{
	set_index_limit(stack_a, stack_b, count);
	high_limit(stack_a, stack_b, count, cmd);
	low_limit(stack_a, stack_b, count, cmd);
}

void	sort(t_list **stack_a, t_list **stack_b, t_count *count, t_list **cmd)
{
	count->r_or_rr = 0;
	count->stack_a_idx = 0;
	count->stack_b_idx = 0;
	if (count->stack_a_nb == 0)
	{
		last_sort(stack_b, count, cmd);
		return ;
	}
	if (*stack_b && count_el(*stack_b) > 1)
	{
		go_to_first_el(stack_a);
		choose_value(stack_a, *stack_b, count);
		if (count->stack_b_idx == -1)
			handle_limits(stack_a, stack_b, count, cmd);
		else
		{
			high_insert(stack_a, stack_b, count, cmd);
			low_insert(stack_a, stack_b, count, cmd);
		}
	}
	ft_pb(stack_a, stack_b, cmd);
	count->stack_a_nb--;
	count->stack_b_nb++;
	sort(stack_a, stack_b, count, cmd);
}
