/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leomiran <leomiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:00:45 by leomiran          #+#    #+#             */
/*   Updated: 2026/11/06 20:48:11 by leomiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_strlen_special(const char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && s[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dest;
	size_t	size_source;
	size_t	d;
	size_t	s;

	size_dest = ft_strlen_special(dst, size);
	size_source = ft_strlen(src);
	if (size_dest >= size)
		return (size + size_source);
	d = size_dest;
	s = 0;
	while (d < size && src[s])
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (size_dest + size_source);
}
