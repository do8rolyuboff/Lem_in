#include "libft.h"

/*
** ft_signum extracts the sign of a number.
** it returns 1 if the argument is > 0, -1 if argument is < 0
** and 0 in case of 0.
*/

int	ft_signum(int num)
{
	if (num > 0)
		return (1);
	else if (num < 0)
		return (-1);
	else
		return (0);
}
