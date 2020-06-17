/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/10 18:32:16 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/15 19:28:36 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	del_graph(t_map *f)
{
	if (f->g)
	{
		free(f->g);
		f->g = NULL;
	}
}

void	delete_adj_list(t_hash **h, int hash_size)
{
	t_hash		*tmp;
	t_linked	*head;
	int			i;

	i = 0;
	while (i < hash_size)
	{
		tmp = h[i];
		while (tmp)
		{
			head = tmp->v->neighbour;
			if (head)
				delete_simple_linked_list(&head);
			tmp = tmp->next;
		}
		i++;
	}
}

t_bool	free_isolated_hash_node(t_hash *tmp_h)
{
	ft_putendl_fd("ERROR: room name duplicated", 2);
	ft_memdel((void **)&tmp_h->v->name);
	delete_simple_linked_list(&tmp_h->v->neighbour);
	ft_memdel((void **)&tmp_h->v);
	ft_memdel((void **)&tmp_h);
	return (false);
}
