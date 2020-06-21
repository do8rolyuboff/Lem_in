#include "../lem_in.h"

t_bool	work_with_bfs(t_map *f)
{
	char	b;

	if (bfs(f, f->start_vertex) == false || f->bfs_order[f->end_vertex] == -1)
		return (delete_all_farm(f));
	path_assign(f, f->paths[0]);
	put_back_removed_arcs(f);
	if ((b = find_shortest_path_vertice_in_current_path(f)) == 2)
		b_2(f);
	else if (b == 1)
		b_1(f);
	else if (b == 0)
		b_0(f);
	return (true);
}
