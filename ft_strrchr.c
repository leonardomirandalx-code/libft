/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leomiran <leomiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:00:45 by leomiran          #+#    #+#             */
/*   Updated: 2026/11/06 20:40:05 by leomiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	f;

	f = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)(&s[f]));
	while (f > 0)
	{
		if ((unsigned char)s[f - 1] == (unsigned char)c)
			return ((char *)(&s[f - 1]));
		f--;
	}
	return (NULL);
}
