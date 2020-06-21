#include "libft.h"

/*
** strncmp compares up to the first n characters of the strings
** s1 and s2 by ASCII.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] && s2[i] && s1[i] == s2[i])
			i++;
		else
			return (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}
