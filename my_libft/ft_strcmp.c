#include "libft.h"

/*
** strcmp compares the two strings pointed to by s1 and s2 by ASCII.
** Returns negative integer if the s1 is numerically less than the s2
** string and so on.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] != s2[i])
		return (int)((unsigned char)s1[i] - (unsigned char)s2[i]);
	else
		return (0);
}
