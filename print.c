/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 11:44:38 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/04 16:05:58 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
