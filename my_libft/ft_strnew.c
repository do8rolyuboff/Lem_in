#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*s;

	if (size > size + 1)
		return (NULL);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
	s[size] = '\0';
	return (s);
}
