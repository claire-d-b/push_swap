/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:50:32 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/08 07:44:51 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

static int	is_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	len_wd(char const *str, char *charset)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (is_charset(charset, str[i]))
			break ;
		i++;
	}
	return (i);
}

static size_t	count_tab(char const *s, char *charset)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (is_charset(charset, s[i]) == 0 && (is_charset(charset, s[i + 1]) \
		|| s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static void	*ft_free(char **res, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(res[i]);
		i++;
	}
	free(res);
	res = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char *charset)
{
	size_t	i;
	size_t	j;
	char	**res;

	init_vars_ft_split(&i, &j);
	if (!s || !*s)
		return ((char **)ft_calloc(2, sizeof(char *)));
	res = malloc(sizeof(char *) * (count_tab(s, charset) + 1));
	if (!res)
		return (0);
	while (++i < (size_t)ft_strlen((char *)s))
	{
		while (j < count_tab(s, charset) && s[i] && !is_charset(charset, s[i]))
		{
			res[j] = malloc(sizeof(char) * (len_wd(&s[i], charset) + 1));
			if (!res[j])
				return (ft_free(res, j));
			res[j] = ft_memmove(res[j], &s[i], len_wd(&s[i], charset) + 1);
			res[j][len_wd(&s[i], charset)] = '\0';
			j++;
			i += len_wd(&s[i], charset);
		}
	}
	res[count_tab(s, charset)] = 0;
	return (res);
}
