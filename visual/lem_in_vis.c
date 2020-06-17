/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in_vis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/24 09:18:37 by btrifle           #+#    #+#             */
/*   Updated: 2020/06/14 21:52:13 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

/*
** some constrains: ant number is integer
** x, y room coordinates are greater than 0
** farm.max_paths is initiated and calculated in graph_fill_in
*/

int		flags(int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-h") || ft_strequ(argv[i], "--help"))
		{
			ft_putstr("Usage:\n./lem-in [-h --help] [-v --visual] < map");
			return (0);
		}
		if (ft_strequ(argv[i], "-v") || ft_strequ(argv[i], "--visual"))
			return (1);
		i++;
	}
	return (0);
}

t_bool	main_algorithm(t_map *f)
{
	if (f->max_paths == 1)
		path_assign(f, f->paths[0]);
	else
	{
		delete_edge_temporaly(f);
		if (work_with_bfs(f) == false)
			return (false);
	}
	if (caravane_goes_farward(f) == false)
	{
		ft_putendl_fd("ERROR in paths", 2);
		return (false);
	}
	return (true);
}

int		main(int argc, char **argv)
{
	t_map	farm;
	t_bool	vis;

	vis = false;
	if (flags(argc, argv) == 1)
		vis = true;
	else
		return (0);
	if (initiate_all_variables(&farm) == false)
		return (0);
	if (vis == true)
		visual1(&farm);
	if (main_algorithm(&farm) == false)
		return (0);
	if (vis == true)
		visual2(&farm);
	del_all_linked_lists_in_raw(&farm);
	farm.flag_del_neighbour = false;
	delete_all_farm(&farm);
	return (0);
}
