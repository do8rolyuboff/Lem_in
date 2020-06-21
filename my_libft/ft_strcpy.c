#include "libft.h"

/*
** strcpy copies the source (s2) string into the destination (s1) string.
** The copy includes the null terminating character.
** The behavior of strcpy is undefined if the source and destination overlap.
** Returns the unchanged value of s1.
** char *dst 		A pointer to the array used as the copy destination.
** const char *src	A pointer to the string used as the copy source.
*/

char	*ft_strcpy(char *dst, const char *src)
{
	unsigned char	*p1;
	unsigned char	*p2;
	int				i;

	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	i = 0;
	while (p2[i] != '\0')
	{
		p1[i] = p2[i];
		i++;
	}
	p1[i] = '\0';
	return (dst);
}
