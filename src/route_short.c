#include "lem_in.h"

t_route				*new_route(t_state *state)
{
	t_route *route_tmp;

	if (!(route_tmp = (t_route*)malloc(sizeof(t_route))) ||
		!(route_tmp->path = (t_path*)malloc(sizeof(t_path))))
		error(state);
	route_tmp->len = 0;
	route_tmp->ants = 0;
	route_tmp->use = 1;
	route_tmp->path->ant_name = 0;
	route_tmp->path->name = ft_strdup(state->e->name);
	route_tmp->path->b = NULL;
	route_tmp->path->f = NULL;
	route_tmp->next = NULL;
	return (route_tmp);
}

static void			mark_link(t_state *state, char *first_node, char *second_node)
{
	int			hash_key;
	t_edge		*edge_find;
	t_node		*node_find;

	hash_key = hash(state->nodes_total, second_node);
	node_find = state->node_matrix[hash_key];
	while (ft_strcmp(node_find->name, second_node) != 0)
		node_find = node_find->other_hash;
	if (ft_strcmp(first_node, second_node) == 0)
		node_find = node_find->node_copy;
	edge_find = node_find->begin_edge;
	while (ft_strcmp(edge_find->name, first_node) != 0)
		edge_find = edge_find->next;
	edge_find->use_in_routes++;
}

static void			new_path(t_state *state, t_route *route_current, t_path *tmp_path)
{
	t_path		*back;
	t_node		*node_find;

	while (ft_strcmp(tmp_path->name, state->s->name) != 0)
	{
		if (!(tmp_path->f = (t_path*)malloc(sizeof(t_path))))
			error(state);
		tmp_path->f->ant_name = 0;
		back = tmp_path;
		tmp_path = tmp_path->f;
		tmp_path->b = back;
		node_find = state->node_matrix[hash(state->nodes_total, back->name)];
		while (ft_strcmp(back->name, node_find->name) != 0)
			node_find = node_find->other_hash;
		if (node_find->node_copy && check_copy(node_find, tmp_path->b->b->name))
			node_find = node_find->node_copy;
		if (ft_strcmp(node_find->prev->name, node_find->name) == 0)
			tmp_path->name = ft_strdup(node_find->prev->prev->name);
		else
			tmp_path->name = ft_strdup(node_find->prev->name);
		mark_link(state, tmp_path->name, tmp_path->b->name);
		tmp_path->f = NULL;
		route_current->len++;
	}
	route_current->path->b = tmp_path;
}

static void			add_new_route(t_state *state, t_route *route_tmp)
{
	new_path(state, route_tmp, route_tmp->path);
	queue_clean(state);
	graph_recovery(state, state->solve->next);
	find_crossover(state, route_tmp);
	free_route(route_tmp, route_tmp->path);
	find_other_routes(state, NULL);
	route_recovery(state->e->begin_edge);
}

void				route_short(t_state *state)
{
	t_route		*route;
	t_solve		*new_sol;

	if (!state->solve)
	{
		if (!(state->solve = (t_solve*)malloc(sizeof(t_solve))))
			error(state);
		init_solve(state->solve);
		route = new_route(state);
		new_path(state, route, route->path);
		state->solve->routes = route;
		state->solve->routes_total = 1;
		state->solve->id = 1;
	}
	else
	{
		if (!(new_sol = (t_solve*)malloc(sizeof(t_solve))))
			error(state);
		init_solve(new_sol);
		new_sol->next = state->solve;
		state->solve = new_sol;
		state->solve->id = state->solve->next->id + 1;
		route = new_route(state);
		add_new_route(state, route);
	}
}
