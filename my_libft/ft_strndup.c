#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*ptr;
	size_t	len;

	len = 0;
	while (s[++len])
		;
	if (n >= len)
		n = len;
	if (!(ptr = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	ptr[n] = '\0';
	while (n--)
		*(ptr + n) = *(s + n);
	return (ptr);
}
