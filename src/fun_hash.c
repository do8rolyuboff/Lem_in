/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:17:52 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/15 19:06:13 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

t_bool	check_if_line_ends_backspace(char *str)
{
	if (*str != '\0')
	{
		ft_putstr_fd("ERROR: one line in map ends with backspace ", 2);
		ft_putendl_fd("or room coordinate not int", 2);
		return (false);
	}
	return (true);
}

t_bool	assign_room_if_ok(t_map *f, char *line, char *backsp, t_hash *tmp_h)
{
	int		place;
	t_hash	*tmp2;

	place = hash_calculate(line, backsp - line, f->hash_size);
	tmp2 = f->first_raw[place];
	while (tmp2 != NULL)
	{
		if (ft_strncmp(tmp2->v->name, line, backsp - line) == 0)
			return (free_isolated_hash_node(tmp_h));
		tmp2 = tmp2->next;
	}
	if (f->first_raw[place] == NULL)
		f->first_raw[place] = tmp_h;
	else
	{
		tmp_h->next = f->first_raw[place];
		f->first_raw[place] = tmp_h;
	}
	return (true);
}

t_bool	check_x_y_if_duplicate(t_map *f, t_hash *t)
{
	int		i;
	t_hash	*tmp;

	i = 0;
	while (i < f->hash_size)
	{
		tmp = f->first_raw[i];
		while (tmp)
		{
			if (tmp != t && tmp->v->x == t->v->x && tmp->v->y == t->v->y)
			{
				ft_putstr_fd("ERROR: in ", 2);
				ft_putstr_fd(t->v->name, 2);
				ft_putendl_fd(": duplicate of coordinates", 2);
				return (false);
			}
			tmp = tmp->next;
		}
		i++;
	}
	return (true);
}

/*
** function creates v vertex and assigns st status (start,middle,end)
** name of vertex *line [without coordinates!], and order in graph
** then increases f->max_order by 1.
** Obviosely, when finished max_order will keep total number of vertice
** We parse the room until backspace
** Then we parse room coordinates
** The room coordinates end strictly with some digit.
*/

t_bool	assign_line_to_hashmap(t_map *f, t_status st, char *line)
{
	t_hash	*tmp_h;
	char	*backsp;

	if (!(tmp_h = (t_hash *)malloc(sizeof(t_hash))))
		return (false);
	tmp_h->next = NULL;
	if ((backsp = ft_strchr(line, ' ')) == NULL ||
	((tmp_h->v = vertex_init(line, backsp - line, st, f->max_order))) == NULL)
		return (false);
	assign_start_end_status(f, st);
	if (assign_room_if_ok(f, line, backsp, tmp_h) == false)
		return (false);
	backsp = ft_atoi_pointer(backsp, &tmp_h->v->x);
	backsp = ft_atoi_pointer(backsp, &tmp_h->v->y);
	if (check_x_y_if_duplicate(f, tmp_h) == false)
		return (false);
	if (tmp_h->v->x < 0 || tmp_h->v->y < 0)
	{
		ft_putstr_fd("ERROR missing one of coordinates\n", 2);
		return (false);
	}
	if (check_if_line_ends_backspace(backsp) == false)
		return (false);
	ft_printf("%s\n", line);
	return (true);
}

/*
** now we have encountered ##start or ##end
** it means we need to free the current line and read next line
** the next line should be room.
** The next coming line after free(line) should be not 0 length,
** doesn't contain '-' and not comment
*/

char	*assign_start_end_to_hashmap(t_map *f, char *line, t_status st)
{
	int		res;

	free(line);
	res = get_next_line(0, &line);
	if (res == 0 || !is_room(line) ||
	assign_line_to_hashmap(f, st, line) == false)
	{
		delete_line_and_farm(f, &line);
		return (NULL);
	}
	return (line);
}
