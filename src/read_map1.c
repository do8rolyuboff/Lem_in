/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <btrifle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 15:16:14 by ogeonosi          #+#    #+#             */
/*   Updated: 2020/06/15 18:14:11 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

/*
** if anything except digit or '+' or ' ' then return false
** otherwise line is ok and ready for ft_atoi, return true
** I know that we check the empty line in previous line, but
** for some reason we check it one more time here
** if false, we free(line) in the read function,
** possibly in main.
** if (*i_addr == 0) //if the line is zero length return false
*/

t_bool	check_for_digits_in_line(char *line)
{
	int		i;
	char	first;

	i = 0;
	while (line[i] == ' ' && line[i] != '\0')
		i++;
	first = line[i];
	while (line[i] != '\0')
	{
		if (!ft_isdigit(line[i]) || line[i] == '+')
			return (false);
		i++;
	}
	if (i == 0 || i > 10 || (i == 10 && first > '2'))
		return (false);
	return (true);
}

/*
** in first line we check: (1) it's not empty, (2) it contains
** only digits, possibly + sign, or backspace, (3) then we atoi
** the line. (4) if ants number is 0 we return false,
** (5) if there is a number and it's int32 then we
** set flag_ants to true and return true
** if OK, we FREE the line
*/

t_bool	check_ant_line(t_map *f, char **line)
{
	if (get_next_line(0, line) <= 0)
		return (delete_line_and_farm(f, line));
	if (!check_for_digits_in_line(*line))
		return (delete_line_and_farm(f, line));
	f->ants = ft_atoi(*line);
	ft_printf("%s\n", *line);
	free(*line);
	*line = NULL;
	if (f->ants <= 0)
		return (delete_line_and_farm(f, line));
	f->flag_ants = true;
	return (true);
}

t_bool	parse_ants(t_map *f, char **line)
{
	if (!check_ant_line(f, line))
	{
		ft_putendl_fd("ERROR in ants number", 2);
		return (false);
	}
	return (true);
}

/*
** There was || res_gnl == 0 in gnl.
** means that there is one empty line
*/

t_bool	check_if_flags_initialized(t_map *f, char **line)
{
	if (f->flag_start == false || f->flag_end == false
	|| f->flag_links == false)
	{
		ft_putstr_fd("ERROR start/end room absent or no links ", 2);
		ft_putendl_fd("between rooms", 2);
		delete_line_and_farm(f, line);
		return (false);
	}
	ft_memdel((void **)line);
	ft_printf("\n");
	return (true);
}

/*
** if during gnl we encounter false, we free it in main function
** that's why we need line link from main function
** otherwise we free the line here
** d is used for dash in this function
** if (!check_ant_line(f, line)) //if ok, then f->flag_ants = true
** if (is_command(f, &line) == false) //if the line with # wasn't
** 		parsed then bad. Убрал || f->flag_rooms == true)
*/

t_bool	read_map(t_map *f, char **line)
{
	if (parse_ants(f, line) == false)
		return (false);
	while (get_next_line(0, line) > 0)
	{
		if (ft_strlen(*line) == 0)
		{
			ft_putendl_fd("ERROR empty line", 2);
			return (delete_line_and_farm(f, line));
		}
		if ((*line)[0] == '#')
		{
			if (is_command(f, line) == false)
				return (false);
		}
		else if (is_room(*line))
		{
			if (assign_room(f, *line) == false)
				return (false);
		}
		else if ((ft_strchr(*line, '-')) &&
			parse_links(f, *line, ft_strchr(*line, '-')) == 0)
			return (false);
		ft_memdel((void **)line);
	}
	return (check_if_flags_initialized(f, line));
}
