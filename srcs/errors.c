/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 05:20:35 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/05 12:14:38 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

int	is_not_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(ft_isdigit(str[i]) && !(str[i] == '-')))
			return (1);
		i++;
	}
	return (0);
}

int	check_doublons(char *str, char **args, int x)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_strcmp(str, args[i]) == 0 && i != x)
			return (1);
		i++;
	}
	return (0);
}

int	handle_errors(int count, char **args)
{
	int		i;
	int		number;
	char	*string;

	i = 1;
	string = NULL;
	number = 0;
	if (count < 2)
		return (-1);
	while (args[i])
	{
		number = ft_atoi(args[i]);
		string = ft_itoa(number);
		if (ft_strcmp(string, args[i]) || is_not_numeric(args[i]) || \
		check_doublons(args[i], args, i))
		{
			free_string(string);
			return (1);
		}
		free_string(string);
		i++;
	}
	return (0);
}
