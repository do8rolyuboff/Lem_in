#include "libft.h"

void	ft_strclr(char *s)
{
	char *str;

	if (!s)
		return ;
	str = s;
	while (*str)
	{
		*str = '\0';
		str++;
	}
}
