#include "libft.h"

int		ft_putstr(char const *s)
{
	int		n;

	if (s)
	{
		n = (int)ft_strlen(s);
		write(1, s, n);
		return (n);
	}
	else
		return (-1);
}
