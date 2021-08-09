/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:38:59 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/09 19:06:22 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "push_swap.h"

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

void	free_string(char *str)
{
	ft_memdel(str, ft_strlen(str), 0);
	free(str);
	str = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free_string(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
	tab = NULL;
}

void	free_stacks(t_list **cmd, t_list **stack_a, t_list **stack_b)
{
	free_stack(*cmd);
	free_stack(*stack_a);
	free_stack(*stack_b);
}
