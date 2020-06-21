#include "libft.h"

void	ft_striter(char *s, void (*f)(char *s))
{
	char *str;

	str = s;
	if (s && f)
	{
		while (*str)
		{
			f(str);
			str++;
		}
	}
}
