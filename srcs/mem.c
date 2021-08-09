/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clde-ber <clde-ber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:57:56 by clde-ber          #+#    #+#             */
/*   Updated: 2021/08/08 07:49:13 by clde-ber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../includes/push_swap.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*tmp_src;
	unsigned char	*tmp_dst;

	if (!dst && !src)
		return (NULL);
	if (src <= dst)
	{
		tmp_dst = (unsigned char *)dst;
		tmp_src = (unsigned char *)src;
		while (len--)
			tmp_dst[len] = tmp_src[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	return (dst);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (0);
	while (i < count * size)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

void	ft_memdel(void *p, size_t size, size_t n)
{
	while (n < size)
	{
		*(char *)p = '\0';
		p++;
		n++;
	}
}
