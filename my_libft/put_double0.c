#include "libft.h"

void	normalize(t_uint *a, t_uint *s, int i)
{
	if (s[i + 1] > 4)
	{
		s[i]++;
		while (s[i] > 9 && i > 0)
		{
			s[i] -= 10;
			s[i - 1] += 1;
			i--;
		}
		if (i == 0)
		{
			a[1]++;
			i = 1;
			while (a[i] > 9)
			{
				a[i] -= 10;
				a[i + 1]++;
				i++;
			}
		}
	}
}
