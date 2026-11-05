/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leomiran <leomiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:00:45 by leomiran          #+#    #+#             */
/*   Updated: 2026/11/04 23:00:45 by leomiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_helper(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	size_t	f;

	f = ft_strlen_helper(s);
	if (c == '\0')
		return ((char *)(&s[f]));
	while (f > 0)
	{
		if (s[f - 1] == c)
			return ((char *)(&s[f - 1]));
		f--;
	}
	return (NULL);
}
