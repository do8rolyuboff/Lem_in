#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	n;
	char			*str;
	char			*result;

	if (!s)
		return (NULL);
	str = (char *)s;
	n = 0;
	while (str[n])
		n++;
	result = (char *)malloc(sizeof(char) * (n + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		result[i] = f(i, str[i]);
		i++;
	}
	result[n] = '\0';
	return (result);
}
