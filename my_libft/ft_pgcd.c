#include "libft.h"

/*
** ft_pgcd returns greatest common divisor of two integers.
*/

int	ft_pgcd(int a, int b)
{
	if (a == 0)
		return (b);
	if (b == 0)
		return (a);
	return (ft_pgcd(b, (a % b)));
}
