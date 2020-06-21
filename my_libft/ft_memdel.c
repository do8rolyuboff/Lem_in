#include "libft.h"

void	ft_memdel(void **ap)
{
	unsigned char **s;

	s = (unsigned char **)ap;
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}
