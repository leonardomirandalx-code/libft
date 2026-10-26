#include "libft.h"

static size_t	ft_strlen_helper(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static	size_t	ft_strlen_special(const char *s, size_t size)
{
	size_t	i;

	i = 0;
	while (s[i] && i < size)
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
	size_source = ft_strlen_helper(src);
	if (size_dest >= size)
		return (size);
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
