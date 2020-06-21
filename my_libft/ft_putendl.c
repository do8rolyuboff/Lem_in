#include "libft.h"

void	ft_putendl(char const *s)
{
	char	*ptr;

	if (s)
	{
		ptr = (char *)s;
		while (*ptr)
		{
			write(1, ptr, 1);
			ptr++;
		}
		write(1, "\n", 1);
	}
}
