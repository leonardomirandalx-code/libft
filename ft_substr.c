#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;
	size_t	measure;

	if (!s)
		return (NULL);
	if (ft_strlen(s) == 0 || start > ft_strlen(s))
	{
		substring = malloc(1);
		if (substring == NULL)
			return (NULL);
		substring[0] = '\0';
		return (substring);
	}
	measure = ft_strlen(s) - start;
	if (measure >= len)
		measure = len;
	i = 0;
	substring = malloc(measure + 1);
	if (substring == NULL)
		return (NULL);
	while (i < measure)
		substring[i++] = s[start++];
	substring[i] = '\0';
	return (substring);
}
