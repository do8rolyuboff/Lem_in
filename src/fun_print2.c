#include "../lem_in.h"

void	print_during_hash(t_hash *tmp)
{
	t_linked	*head;

	while (tmp)
	{
		ft_printf("\033[0;35m%s\033[0m; st: %d; \
		\033[0;32mord:%d\033[0m\033[0;31m->\033[0m", tmp->v->name, \
		tmp->v->status, tmp->v->order);
		head = tmp->v->neighbour;
		while (head)
		{
			ft_printf("%d->", head->data);
			head = head->next;
		}
		ft_printf("nil \n");
		tmp = tmp->next;
	}
}

void	print_hash(t_hash **h, int hash_size)
{
	t_hash		*tmp;
	int			i;

	i = 0;
	while (i < hash_size)
	{
		tmp = h[i];
		ft_printf("%d: ", i);
		print_during_hash(tmp);
		ft_printf("NULL\n");
		i++;
	}
}

void	print_linked_list(t_linked **head)
{
	t_linked	*tmp;

	tmp = *head;
	while (tmp)
	{
		ft_printf("%d->", tmp->data);
		tmp = tmp->next;
	}
	ft_printf("NULL\n");
}
