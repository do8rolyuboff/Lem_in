#include "libft.h"

/*
** If the argument is an upper-case letter, the tolower() function returns
** the corresponding lower-case letter if there is one;
** otherwise, the argument is returned unchanged.
** The argument must be representable as an unsigned char.
*/

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c = c + 32;
	return (c);
}
