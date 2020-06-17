/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_farm1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 17:27:31 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/15 18:31:29 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

void	del_all_linked_lists_in_raw(t_map *f)
{
	int i;

	i = 0;
	while (i < f->max_order)
	{
		delete_simple_linked_list(&f->g[i]);
		i++;
	}
}

void	del_neigbours(t_map *f)
{
	int			i;
	t_hash		*h;
	t_vertex	*v;

	i = 0;
	while (i < f->hash_size)
	{
		h = f->first_raw[i];
		while (h)
		{
			v = h->v;
			if (v->neighbour)
				delete_simple_linked_list(&v->neighbour);
			h = h->next;
		}
		i++;
	}
}

void	delete_others(t_map *f)
{
	del_vertice(f);
	del_nodes(f);
	del_raws(f);
	del_graph(f);
	ft_memdel((void **)&f->rooms_ordered);
	ft_memdel((void **)&f->bfs_order);
	ft_memdel((void **)&f->shortest_path);
	del_paths(f);
	del_ants_in_paths_len_pos(f);
}

t_bool	delete_all_farm(t_map *f)
{
	int			i;
	t_hash		*h;
	t_vertex	*v;

	i = 0;
	while (i < f->hash_size)
	{
		h = f->first_raw[i];
		while (h)
		{
			v = h->v;
			del_name(v->name);
			h = h->next;
		}
		i++;
	}
	if (f->flag_del_neighbour == true)
		del_neigbours(f);
	delete_others(f);
	return (false);
}

/*
** used in readmap to get rid of residues in gnl
*/

t_bool	delete_line_and_farm(t_map *f, char **line)
{
	free(*line);
	get_next_line(0, line);
	free(*line);
	delete_all_farm(f);
	return (false);
}
