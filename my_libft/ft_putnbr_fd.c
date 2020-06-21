#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	m;

	m = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (m > 9)
		ft_putnbr_fd(m / 10, fd);
	ft_putchar_fd(m % 10 + '0', fd);
}
