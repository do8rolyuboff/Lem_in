#include "libft.h"

/*
** Tests for ASCII character, code between 0 and 0x7f = 7 * 16 + 15.
** Returns non-zero if test is true.
*/

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
