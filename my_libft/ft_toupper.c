#include "libft.h"

/*
** If the argument is a lower-case letter, the toupper() function returns
** the corresponding upper-case letter if there is one;
** otherwise, the argument is returned unchanged.
** The argument must be representable as an unsigned char.
*/

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
