#include "libft.h"

/*
** isalnum tests whether the character c is in one of the following:
** 'a'to 'z' 'A to 'Z' '0' to '9'
** Note: the argument must be representable as an unsigned char.
** Otherwise the behavior of the function is undefined.
*/

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c >= 65 && c <= 90)
		return (1);
	else if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
