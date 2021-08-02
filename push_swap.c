/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 13:20:07 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/02 12:34:15 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_list *s_lst)
{
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

int	main(int ac, char **av)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*cmd;
	int		*nb;

	i = 1;
	cmd = NULL;
	nb = malloc(sizeof(int));
	*nb = ft_atoi(av[i]);
	init_stacks(&stack_a, &stack_b);
	if (ac < 2)
		return (0);
	stack_a = ft_lstnew(nb);
	i++;
	while (i < ac)
	{
		nb = malloc(sizeof(int));
		*nb = ft_atoi(av[i]);
		ft_lst_addback(&stack_a, ft_lstnew(nb));
		i++;
	}
	push_swap(&stack_a, &stack_b, ac - 1, &cmd);
	if (checker(stack_a))
		printf("OK");
	print_no_details(stack_a, stack_b);
	go_to_first_el(&cmd);
	print_commands(&cmd);
	print_count(&cmd);
	free_stack(stack_a);
	free_stack(cmd);
	free_stack(stack_b);
	return (0);
}
