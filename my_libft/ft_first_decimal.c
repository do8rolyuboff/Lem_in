#include "libft.h"

int	ft_first_decimal(int n)
{
	int dec;

	dec = 1;
	while (n > 9)
	{
		dec *= 10;
		n /= 10;
	}
	return (dec);
}
