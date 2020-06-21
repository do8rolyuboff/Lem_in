#include "libft.h"

/*
** Tests for ASCII character, code between 0 and 0x7f = 7 * 16 + 15.
** Returns non-zero if test is true.
*/

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
