#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned char *p1;
	unsigned char *p2;

	if (!s1 || !s2)
		return (0);
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	while (*p1 && *p2 && *p1 == *p2)
	{
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return (1);
	else
		return (0);
}
