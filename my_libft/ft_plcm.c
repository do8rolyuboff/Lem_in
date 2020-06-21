#include "libft.h"

/*
** returns least common multiple
*/

int		ft_plcm(int a, int b)
{
	return (a * b / ft_pgcd(a, b));
}
