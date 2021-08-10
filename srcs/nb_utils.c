/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 15:01:04 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/10 10:52:27 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_int(int n)
{
	int	i;

	i = 0;
	if (n == INT_MIN)
		return (11);
	else if (n <= INT_MAX && n > INT_MIN)
	{
		if (n == 0)
			return (1);
		if (n < 0)
		{
			n = -n;
			i += 1;
		}
		while (n > 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

static int	ft_pow(int nb, int pow)
{
	int	i;
	int	res;

	i = 0;
	res = 1;
	while (i < pow)
	{
		res = res * nb;
		i++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	i = -1;
	k = n;
	j = len_int(k);
	str = malloc(sizeof(char) * (len_int(n) + 1));
	if (!str)
		return (0);
	if ((int)n < 0 && k != INT_MIN)
		n = -n;
	while (j-- > 0 && k != INT_MIN)
		if (i++ <= len_int(k))
			str[j] = ((n / ft_pow(10, i)) % 10) + '0';
	str[len_int(k)] = '\0';
	if (k < 0 && k != INT_MIN)
		str[0] = '-';
	return (str);
}
