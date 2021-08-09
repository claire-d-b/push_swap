/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_lists.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 12:37:54 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/08 07:36:05 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

void	sort_three_numbers(t_list **stack_a, t_list **cmd)
{
	t_list	*tmp;

	tmp = 0;
	go_to_last_el(stack_a);
	tmp = *stack_a;
	go_to_first_el(stack_a);
	if (checker(*stack_a) == 0)
		return ;
	else if (*(int *)(*stack_a)->value > *(int *)(*stack_a)->next->value && \
			(*(int *)(*stack_a)->value > *(int *)tmp->value))
		ft_ra(*stack_a, cmd);
	else if (*(int *)(*stack_a)->value < *(int *)(*stack_a)->next->value)
		ft_rra(*stack_a, cmd);
	go_to_first_el(stack_a);
	if (*(int *)(*stack_a)->value > *(int *)(*stack_a)->next->value)
	{
		ft_sa(*stack_a);
		ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sa")));
	}
}

void	place_smallest_nbs(int *idx, int count, t_list **stack_a, t_list **cmd)
{
	if (*idx > count / 2)
	{
		*idx = count - *idx;
		while (*idx)
		{
			ft_rra(*stack_a, cmd);
			(*idx)--;
		}
	}
	else
	{
		while (*idx)
		{
			ft_ra(*stack_a, cmd);
			(*idx)--;
		}
	}
}

void	swap_list_two_el(t_list **stack_a, t_list **cmd)
{
	if (*(int *)(*stack_a)->value > *(int *)(*stack_a)->next->value)
	{
		ft_sa(*stack_a);
		ft_lst_addback(cmd, ft_lstnew((char *)ft_strdup("sa")));
	}
}

void	up_to_five_numbers(t_list **stack_a, t_list **stack_b, t_list **cmd, \
		int count)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = count;
	idx = 0;
	if (count == 2)
		swap_list_two_el(stack_a, cmd);
	else if (count >= 3)
	{
		while (j > 3)
		{
			idx = index_max_el(stack_a, find_min(*stack_a));
			place_smallest_nbs(&idx, count, stack_a, cmd);
			ft_pb(stack_a, stack_b, cmd);
			j--;
		}
		sort_three_numbers(stack_a, cmd);
		while (j < count)
		{
			ft_pa(stack_a, stack_b, cmd);
			j++;
		}
	}
}
