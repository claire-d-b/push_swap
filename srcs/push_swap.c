/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:20:07 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/10 11:46:24 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_list *s_lst)
{
	go_to_first_el(&s_lst);
	while (s_lst->next)
	{
		if (*(int *)s_lst->value > *(int *)(s_lst->next->value))
			return (FALSE);
		s_lst = s_lst->next;
	}
	return (TRUE);
}

void	push_swap(t_list **stack_a, t_list **stack_b, int nb, t_list **cmd)
{
	int		x;
	int		max;
	int		j;
	t_count	count;

	x = 0;
	j = nb;
	max = 0;
	init_struct_count(&count, nb);
	sort(stack_a, stack_b, &count, cmd);
	if (*stack_b)
		go_to_first_el(stack_b);
	while (*stack_b)
		ft_pa(stack_a, stack_b, cmd);
}

void	save_integer(int *nb, char *str, t_list **stack_a)
{
	nb = malloc(sizeof(int));
	*nb = ft_atoi(str);
	ft_lst_addback(stack_a, ft_lstnew(nb));
}

int	set_args(char **av, int **nb, t_list **stack_a)
{
	int		i;
	int		j;
	char	**split;

	i = 0;
	j = -1;
	split = NULL;
	while (av[++i])
	{
		split = ft_split(av[i], " \t\n\r\v\f");
		while (split[++j] || (!(split[0]) && j == 0))
		{
			if (!(split[0]) || (split[0] && handle_errors(split) == ERROR))
			{
				if (!(split[0]))
					ft_putstr_fd("Error\n", 2);
				free_tab(split);
				return (FALSE);
			}
			save_integer(*nb, split[j], stack_a);
		}
		free_tab(split);
		j = -1;
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*cmd;
	int		*nb;

	nb = NULL;
	cmd = NULL;
	init_stacks(&stack_a, &stack_b);
	if (ac < 2 || set_args(av, &nb, &stack_a) || (stack_a && \
	list_doublons(stack_a)))
	{
		free_stack(stack_a);
		return (0);
	}
	if (ac <= 6 && stack_a && checker(stack_a))
		up_to_five_numbers(&stack_a, &stack_b, &cmd, count_el(stack_a));
	else if (stack_a && checker(stack_a))
		push_swap(&stack_a, &stack_b, count_el(stack_a), &cmd);
	go_to_first_el(&cmd);
	print_commands(&cmd);
	free_stacks(&cmd, &stack_a, &stack_b);
	return (0);
}
