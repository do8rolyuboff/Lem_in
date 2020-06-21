#include "libft.h"

void	ft_strdel(char **as)
{
	char **s;

	s = as;
	if (s && *s)
	{
		free(*s);
		*s = NULL;
	}
}
