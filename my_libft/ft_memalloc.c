#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)malloc(sizeof(unsigned char) * size);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		s[i] = '\0';
		i++;
	}
	return ((void *)(s));
}
