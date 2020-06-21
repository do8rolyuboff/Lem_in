#include "libft.h"

/*
** isalpha tests whether c is in one of the following sets
** of alphabetic characters: 'a' to 'z' 'A' to 'Z'
** Note: the argument must be representable as an unsigned char or be
** equal to EOF, otherwise the behavior of the function is undefined.
*/

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
