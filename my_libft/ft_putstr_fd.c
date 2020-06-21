#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	char *ptr;

	if (s)
	{
		ptr = (char *)s;
		while (*ptr)
		{
			write(fd, ptr, 1);
			ptr++;
		}
	}
}
