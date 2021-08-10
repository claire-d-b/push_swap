/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:37:17 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/10 10:53:12 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_ss(t_list *stack_a, t_list *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}

void	ft_sa(t_list *stack)
{
	go_to_last_el(&stack);
	if (count_el(stack) > 1)
		ft_swap(stack->prec->value, stack->value);
}

void	ft_sb(t_list *stack)
{
	go_to_last_el(&stack);
	if (count_el(stack) > 1)
		ft_swap(stack->prec->value, stack->value);
}
