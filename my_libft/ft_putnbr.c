#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int	m;

	m = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	if (n < 0)
		ft_putchar('-');
	if (m > 9)
		ft_putnbr(m / 10);
	ft_putchar(m % 10 + '0');
}
