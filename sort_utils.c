/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:50:32 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/02 12:24:48 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	high_limit(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd)
{
	if (count->stack_b_idx > count->stack_b_nb / 2)
	{
		while (count->stack_b_idx < count->stack_b_nb && count->r_or_rr == 1 \
		&& count->stack_a_idx)
		{
			ft_rrr(*stack_a, *stack_b, cmd);
			count->stack_b_idx++;
			count->stack_a_idx--;
		}
		while (count->r_or_rr == 1 && count->stack_a_idx)
		{
			ft_rra(*stack_a, cmd);
			count->stack_a_idx--;
		}
		while (count->r_or_rr == 0 && count->stack_a_idx)
		{
			ft_ra(*stack_a, cmd);
			count->stack_a_idx--;
		}
		while (count->stack_b_idx < count->stack_b_nb)
		{
			ft_rrb(*stack_b, cmd);
			count->stack_b_idx++;
		}
	}
}

void	low_limit(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd)
{
	if (count->stack_b_idx <= count->stack_b_nb / 2)
	{
		while (count->stack_b_idx > 0 && count->r_or_rr == 0 && \
		count->stack_a_idx)
		{
			ft_rr(*stack_a, *stack_b, cmd);
			count->stack_b_idx--;
			count->stack_a_idx--;
		}
		while (count->r_or_rr == 0 && count->stack_a_idx)
		{
			ft_ra(*stack_a, cmd);
			count->stack_a_idx--;
		}
		while (count->r_or_rr == 1 && count->stack_a_idx)
		{
			ft_rra(*stack_a, cmd);
			count->stack_a_idx--;
		}
		while (count->stack_b_idx > 0)
		{
			ft_rb(*stack_b, cmd);
			count->stack_b_idx--;
		}
	}
}

void	high_insert(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd)
{
	if (count->stack_b_idx > count->stack_b_nb / 2)
	{
		while (count->stack_b_idx < count->stack_b_nb - 1 && \
		count->r_or_rr == 1 && count->stack_a_idx)
		{
			ft_rrr(*stack_a, *stack_b, cmd);
			count->stack_b_idx++;
			count->stack_a_idx--;
		}
		while (count->r_or_rr == 1 && count->stack_a_idx)
		{
			ft_rra(*stack_a, cmd);
			count->stack_a_idx--;
		}
		while (count->r_or_rr == 0 && count->stack_a_idx)
		{
			ft_ra(*stack_a, cmd);
			count->stack_a_idx--;
		}
		while (count->stack_b_idx < count->stack_b_nb - 1)
		{
			ft_rrb(*stack_b, cmd);
			count->stack_b_idx++;
		}
	}
}

void	low_insert(t_list **stack_a, t_list **stack_b, t_count *count, \
t_list **cmd)
{
	if (count->stack_b_idx <= count->stack_b_nb / 2)
	{
		while (count->stack_b_idx >= 0 && count->r_or_rr == 0 && \
		count->stack_a_idx)
		{
			ft_rr(*stack_a, *stack_b, cmd);
			count->stack_b_idx--;
			count->stack_a_idx--;
		}
		while (count->r_or_rr == 0 && count->stack_a_idx)
		{
			ft_ra(*stack_a, cmd);
			count->stack_a_idx--;
		}
		while (count->r_or_rr == 1 && count->stack_a_idx)
		{
			ft_rra(*stack_a, cmd);
			count->stack_a_idx--;
		}
		while (count->stack_b_idx >= 0)
		{
			ft_rb(*stack_b, cmd);
			count->stack_b_idx--;
		}
	}
}
