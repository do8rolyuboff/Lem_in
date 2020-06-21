#include "libft.h"

/*
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap;
** the copy is always done in a non-destructive manner.
** memmove() returns the original value of dst.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*p1;
	unsigned char	*p2;

	if (dst == NULL && src == NULL)
		return (NULL);
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	if (p1 < p2)
	{
		while (len--)
			*p1++ = *p2++;
	}
	if (p1 > p2)
	{
		while (len--)
			*(p1 + len) = *(p2 + len);
	}
	return (dst);
}
