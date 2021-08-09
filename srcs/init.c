/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:45:47 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/09 18:27:08 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

void	init_four_values(int *i, int *k, int *boolean, int *ct)
{
	*i = 0;
	*k = 0;
	*boolean = 0;
	*ct = 0;
}

int	init_stacks(t_list **stack_a, t_list **stack_b)
{
	*stack_a = NULL;
	*stack_b = NULL;
	return (0);
}

void	init_struct_count(t_count *count, int args_nb)
{
	count->count = 0;
	count->start_nb = args_nb;
	count->stack_a_nb = args_nb;
	count->stack_b_nb = 0;
	count->r_or_rr = 0;
	count->stack_a_idx = 0;
	count->stack_b_idx = 0;
	count->real_index_b = 0;
}

void	init_vars_ft_split(size_t *i, size_t *j)
{
	*i = -1;
	*j = 0;
}
