#include "libft.h"

/*
** isdigit tests whether c is one of the following decimal digit characters:
** '0' '1' '2' '3' '4' '5' '6' '7' '8' '9'
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
