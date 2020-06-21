#include "libft.h"

t_list	*ft_lstnew_gnl(int buff_size, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	new->content = ft_strnew(buff_size + 1);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
