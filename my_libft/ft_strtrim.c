#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*tmp;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	j = len - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (!(tmp = ft_strndup(s + i, j + 1 - i)))
		return (NULL);
	return (tmp);
}
