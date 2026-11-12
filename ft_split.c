/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leomiran <leomiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:00:44 by leomiran          #+#    #+#             */
/*   Updated: 2026/11/11 21:13:28 by leomiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static size_t	ft_size_words(char const *s, char c, size_t i)
{
	size_t	size;

	size = 0;
	while (s[i] && s[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static size_t	ft_checkup(char **strings, size_t j)
{
	if (strings[j] == NULL)
	{
		while (j > 0)
		{
			free (strings[j - 1]);
			j--;
		}
		return (0);
	}
	return (1);
}

static char	**ft_make_s(char const *s, char **strings, char c, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	size_word;

	i = 0;
	j = 0;
	while (j < n)
	{
		while (s[i] == c)
			i++;
		size_word = ft_size_words(s, c, i);
		strings[j] = ft_substr(s, i, size_word);
		if (!ft_checkup(strings, j))
			return (NULL);
		j++;
		i += size_word;
	}
	strings[j] = NULL;
	return (strings);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	size_t	number_words;

	if (!s)
		return (NULL);
	number_words = ft_count_words(s, c);
	strings = malloc((number_words + 1) * (sizeof(char *)));
	if (strings == NULL)
		return (NULL);
	if (ft_make_s(s, strings, c, number_words) == NULL)
	{
		free (strings);
		return (NULL);
	}
	return (strings);
}
