#include "libft.h"

/*
** bzero() erases the data in the n bytes of the memory starting at s,
** by writing zeros (bytes containing '\0') to that area.
*/

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	int				i;
	int				n1;

	p = (unsigned char *)s;
	i = 0;
	n1 = (int)n;
	while (i < n1)
	{
		*p = '\0';
		p++;
		i++;
	}
}
