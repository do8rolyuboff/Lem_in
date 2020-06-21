#include "libft.h"

/*
** strcat appends the string s2 (including '\0') onto the end of the string s1.
** The first character of s2 overwrites '\0' of s1.
** The string pointed to s1 must be large enough
** to accept the extra characters from s2.
** Returns the unchanged value of s1.
*/

char	*ft_strcat(char *s1, const char *s2)
{
	char *p1;
	char *p2;

	p1 = (char *)s1;
	p2 = (char *)s2;
	while (*p1)
		p1++;
	while (*p2)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	*p1 = '\0';
	return (s1);
}
