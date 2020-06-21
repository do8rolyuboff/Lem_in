#include "../lem_in.h"

/*
** initialize farm variables
** 100 used
** the only place where we allcate memory is hashmap_init
** flag_del_neighbour is true by default
*/

void	farm_init(t_map *f)
{
	f->ants = 0;
	f->start_vertex = 0;
	f->end_vertex = 0;
	f->hash_size = 10;
	f->ants = 0;
	f->flag_ants = false;
	f->flag_start = false;
	f->flag_end = false;
	f->flag_rooms = false;
	f->flag_links = false;
	f->found_shortest_path = false;
	f->max_order = 0;
	f->bfs_order = NULL;
	f->g = NULL;
	f->shortest_path = NULL;
	f->paths = NULL;
	f->current_path = 0;
	f->max_paths = 0;
	f->arc1 = NULL;
	f->arc2 = NULL;
	f->pos = NULL;
	f->len = NULL;
	f->ants_in_paths = NULL;
	f->rooms_ordered = NULL;
	f->flag_del_neighbour = true;
}

/*
** allocate memory for hash table and initialize it with NULLs
*/

t_hash	**hashmap_init(t_hash **h, int hash_size)
{
	int i;

	h = (t_hash **)malloc(sizeof(t_hash *) * hash_size);
	if (h == NULL)
		return (NULL);
	i = -1;
	while (++i < hash_size)
		h[i] = NULL;
	return (h);
}

void	assign_start_end_status(t_map *f, t_status st)
{
	if (st == begin)
		f->start_vertex = f->max_order;
	else if (st == end)
		f->end_vertex = f->max_order;
	f->max_order++;
}

/*
** allocate memory of length n
** and initialize it with value
*/

int		*arr_init(int n, int value)
{
	int	i;
	int	*arr;

	arr = (int *)malloc(sizeof(int) * n);
	i = 0;
	while (i < n)
		arr[i++] = value;
	return (arr);
}

void	arr_fill_in_with_value(int *arr, int n, int value)
{
	int i;

	i = 0;
	while (i < n)
	{
		arr[i] = value;
		i++;
	}
}
