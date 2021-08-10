/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:44:38 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/10 10:52:34 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	errors(char *string, int boolean)
{
	if (boolean)
		ft_putstr_fd("Error\n", 2);
	free_string(string);
	return (ERROR);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	print_commands(t_list **cmd)
{
	go_to_first_el(cmd);
	if (*cmd)
	{
		while ((*cmd)->next)
		{
			ft_putstr_fd((char *)(*cmd)->value, 1);
			ft_putstr_fd("\n", 1);
			*cmd = (*cmd)->next;
		}
		ft_putstr_fd((char *)(*cmd)->value, 1);
		ft_putstr_fd("\n", 1);
	}
}
