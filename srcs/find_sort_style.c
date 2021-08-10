/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sort_style.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:53:09 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/10 10:51:19 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_index(int value, t_list *stack)
{
	int	x;
	int	start_value;

	x = 0;
	go_to_first_el(&stack);
	start_value = *(int *)stack->value;
	while (stack->next)
	{
		if (value < *(int *)stack->value && value > *(int *)stack->next->value)
			return (x);
		stack = stack->next;
		x++;
	}
	if (value < *(int *)stack->value && value > start_value)
		return (x);
	go_to_first_el(&stack);
	return (-1);
}

void	set_if_high_or_low(int i, int *k, int *boolean, t_count *count)
{
	if (i > count->stack_a_nb / 2)
	{
		*boolean = 1;
		*k = count->stack_a_nb - i;
	}
	else
	{
		*boolean = 0;
		*k = i;
	}
}

void	choose_value(t_list **stack_a, t_list *stack_b, t_count *count)
{
	int	i;
	int	ct;
	int	comp;
	int	k;
	int	boolean;

	init_four_values(&i, &k, &boolean, &ct);
	comp = 0;
	while (i < count->stack_a_nb)
	{
		ct = find_index(*(int *)(*stack_a)->value, stack_b);
		count->real_index_b = ct;
		set_ct_limit(&ct, stack_a, stack_b, count);
		set_if_high_or_low(i, &k, &boolean, count);
		if (ct + k < comp || i == 0)
		{
			comp = ct + k;
			count->stack_a_idx = k;
			count->r_or_rr = boolean;
			count->stack_b_idx = count->real_index_b;
		}
		if (i < count->stack_a_nb - 1)
			*stack_a = (*stack_a)->next;
		i++;
	}
}
