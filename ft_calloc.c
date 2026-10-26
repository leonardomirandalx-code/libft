#include "libft.h"
#include <stdint.h>
#include <stdlib.h>

static void	ft_bzero_helper(void *s, size_t nmemb, size_t size)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < nmemb * size)
	{
		p[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
	{
		array = malloc(1);
		if (array == NULL)
			return (NULL);
		return (array);
	}
	if (SIZE_MAX / nmemb < size)
		return (NULL);
	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero_helper(array, nmemb, size);
	return (array);
}
