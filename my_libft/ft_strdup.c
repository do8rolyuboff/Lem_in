#include "libft.h"

/*
** Returns a pointer to a new string which is a duplicate of str
*/

char	*ft_strdup(const char *s1)
{
	char	*tmp;
	char	*p;
	size_t	i;
	size_t	n;

	i = 0;
	p = (char *)s1;
	while (p[++i])
		;
	n = i;
	if (!(tmp = (char *)malloc(sizeof(char ) * (n + 1))))
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = p[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
