/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leomiran <leomiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:00:44 by leomiran          #+#    #+#             */
/*   Updated: 2026/11/04 23:00:44 by leomiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_strlen_helper(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strcpy_helper(const char *src, char *dst)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s)
{
	size_t	measure;
	char	*string;

	measure = ft_strlen_helper(s);
	string = malloc((measure + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string = ft_strcpy_helper(s, string);
	return (string);
}
