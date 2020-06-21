#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	char			*str;

	if (s && f)
	{
		str = s;
		i = 0;
		while (str[i])
		{
			f(i, str + i);
			i++;
		}
	}
}
