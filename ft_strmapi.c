#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*string;
	size_t	size;
	size_t	i;

	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	i = 0;
	string = malloc(size + 1);
	if (string == NULL)
		return (NULL);
	while (s[i])
	{
		string[i] = f(1, s[i]);
		i++;
	}
	string[i] = '\0';
	return (string);
}
