/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leomiran <leomiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:00:45 by leomiran          #+#    #+#             */
/*   Updated: 2026/11/04 23:00:45 by leomiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static signed int	ft_isset(char const c, char const *set);

static size_t	ft_trimlen(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (ft_isset(s1[i], set))
		i++;
	if (s1[i] == '\0')
		return (0);
	while (s1[i])
	{
		i++;
		j++;
	}
	i--;
	while (ft_isset(s1[i], set))
	{
		i--;
		j--;
	}
	return (j);
}

static signed int	ft_isset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*string;
	size_t	i;
	size_t	j;

	if (!s1 || !set)
		return (NULL);
	string = malloc(ft_trimlen(s1, set) + 1);
	if (string == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (ft_isset(s1[i], set))
		i++;
	while (s1[i] && j < ft_trimlen(s1, set))
	{
		string[j] = s1[i];
		i++;
		j++;
	}
	string[j] = '\0';
	return (string);
}
