/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:20:07 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/05 11:50:54 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	checker(t_list *s_lst)
{
	go_to_first_el(&s_lst);
	while (s_lst->next)
	{
		if (*(int *)s_lst->value > *(int *)(s_lst->next->value))
			return (0);
		s_lst = s_lst->next;
	}
	return (1);
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

void	print_commands_free_stacks(t_list **cmd, t_list **stack_a, \
t_list **stack_b)
{
	print_commands(cmd);
	free_stack(*cmd);
	free_stack(*stack_a);
	free_stack(*stack_b);
}

void	save_integer(int *nb, char *str, t_list **stack_a)
{
	nb = malloc(sizeof(int));
	*nb = ft_atoi(str);
	ft_lst_addback(stack_a, ft_lstnew(nb));
}

int	main(int ac, char **av)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*cmd;
	int		*nb;

	nb = NULL;
	init_two_values(&i, &cmd);
	if (handle_errors(ac, av) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	init_stacks(&stack_a, &stack_b);
	save_integer(nb, av[i], &stack_a);
	while (++i < ac)
		save_integer(nb, av[i], &stack_a);
	if (ac <= 6 && checker(stack_a) == 0)
		up_to_five_numbers(&stack_a, &stack_b, &cmd, ac - 1);
	else if (checker(stack_a) == 0)
		push_swap(&stack_a, &stack_b, ac - 1, &cmd);
	print_commands_free_stacks(&cmd, &stack_a, &stack_b);
	return (0);
}
