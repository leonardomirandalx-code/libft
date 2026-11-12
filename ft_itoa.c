/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leomiran <leomiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 23:00:41 by leomiran          #+#    #+#             */
/*   Updated: 2026/11/11 21:13:39 by leomiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_measure(int n)
{
	size_t	i;
	long	number;

	number = n;
	i = 0;
	if (number < 0)
	{
		number *= -1;
		i++;
	}
	while (number > 9)
	{
		number /= 10;
		i++;
	}
	i++;
	return (i);
}

static char	*ft_make(char *number, long n, long pos)
{
	number[pos] = '\0';
	pos--;
	if (n >= 0)
	{
		while (pos >= 0)
		{
			number[pos] = n % 10 + '0';
			pos--;
			n /= 10;
		}
	}
	else
	{
		number[0] = '-';
		while (pos > 0)
		{
			number[pos] = (n * -1) % 10 + '0';
			pos--;
			n /= 10;
		}
	}
	return (number);
}

char	*ft_itoa(int n)
{
	char	*number;
	size_t	measure;

	measure = ft_measure(n);
	number = malloc(measure + 1);
	if (number == NULL)
		return (NULL);
	number = ft_make(number, n, measure);
	return (number);
}
