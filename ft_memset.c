#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;//entender conversao
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
