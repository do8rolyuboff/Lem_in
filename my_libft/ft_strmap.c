#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	n;
	char	*result;
	char	*str;

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
		result[i] = f(str[i]);
		i++;
	}
	result[n] = '\0';
	return (result);
}
