#include "../lem_in.h"

/*
** after bfs we check that start and end are in one component
*/

t_bool	is_graph_connected(t_map *f)
{
	if (f->bfs_order[f->end_vertex] == -1)
	{
		ft_putendl_fd("ERROR memory allocation for queue", 2);
		return (false);
	}
	return (true);
}

/*
** here we go through the graph and fill in bfs_order
** if afterwards bfs_order[end_vertex] = -1, the graph is not connected.
** WE assign first element to top
** the other elements are moved up.
** return what in top [and delete it].
** if que is empty then -1 returned
*/

int		top_queue(int *arr, int n)
{
	int			top;
	int			i;

	top = arr[0];
	i = 0;
	while (i < n)
	{
		if (arr[i] != -1)
		{
			arr[i] = arr[i + 1];
			i++;
		}
		else
			break ;
	}
	return (top);
}

/*
** queue functions are here
** insert
**		que[j] = 5;
**		j++;
** delete
**		top = top_queue(que, f->max_order);
**		j--;
** we take room and look all it's neigbours.
** if any of them is unvisited, we put it to queue
** so that we can visit it it next cycle
*/

void	bfs_main(t_map *f, int *que, int start)
{
	t_linked	*tmp;
	int			top;
	int			j;

	f->bfs_order[start] = 0;
	que[0] = f->start_vertex;
	j = 1;
	top = 1;
	while ((top = top_queue(que, f->max_order)) != -1)
	{
		j--;
		tmp = f->g[top];
		while (tmp != NULL)
		{
			if (f->bfs_order[tmp->data] == -1)
			{
				que[j] = tmp->data;
				j++;
				f->bfs_order[tmp->data] = f->bfs_order[top] + 1;
			}
			tmp = tmp->next;
		}
	}
}

/*
** we create que here and fill it with -1's
** we assign to f->bfs_order -1's
** we run bfs_main and free queue
** the main result is that we fill in f->bfs_order.
** This array contains information when each vertex was visited.
*/

t_bool	bfs(t_map *f, int start)
{
	int			*que;

	if (!(que = (int *)malloc(sizeof(int) * f->max_order)))
	{
		ft_putendl_fd("ERROR memory allocation for queue", 2);
		return (false);
	}
	arr_fill_in_with_value(que, f->max_order, -1);
	arr_fill_in_with_value(f->bfs_order, f->max_order, -1);
	bfs_main(f, que, start);
	free(que);
	return (true);
}
