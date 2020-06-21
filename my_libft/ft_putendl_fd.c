#include "libft.h"

int	ft_putendl_fd(char const *s, int fd)
{
	char *ptr;

	if (s)
	{
		ptr = (char *)s;
		write(fd, ptr, ft_strlen(ptr));
		write(fd, "\n", 1);
		return (1);
	}
	return (0);
}
