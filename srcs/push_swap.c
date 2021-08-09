/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:20:07 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/08 07:47:53 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

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

int	set_args(char **av, int **nb, t_list **stack_a, int ac)
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
		while (split[++j])
		{
			if (ac < 2 || handle_errors(split) == ERROR)
			{
				if (!(ac < 2))
					ft_putstr_fd("Error\n", 2);
				free_tab(split);
				return (1);
			}
			save_integer(*nb, split[j], stack_a);
		}
		free_tab(split);
		j = -1;
	}
	return (0);
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
	if (set_args(av, &nb, &stack_a, ac) || list_doublons(stack_a))
	{
		free_stack(stack_a);
		return (0);
	}
	if (ac <= 6 && checker(stack_a))
		up_to_five_numbers(&stack_a, &stack_b, &cmd, count_el(stack_a));
	else if (checker(stack_a))
		push_swap(&stack_a, &stack_b, count_el(stack_a), &cmd);
	go_to_first_el(&cmd);
	print_commands(&cmd);
	free_stacks(&cmd, &stack_a, &stack_b);
	return (0);
}
