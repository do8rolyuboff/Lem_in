#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *lastnode;
	t_list *currentnode;

	if (lst && f)
	{
		head = f(lst);
		if (!head)
			return (NULL);
		lst = lst->next;
		lastnode = head;
		while (lst)
		{
			currentnode = f(lst);
			if (!currentnode)
				return (NULL);
			lastnode->next = currentnode;
			lastnode = currentnode;
			lst = lst->next;
		}
		return (head);
	}
	return (NULL);
}
