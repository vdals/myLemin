#include "lem_in.h"

static void		edges_inverse(t_state *state, t_path *first_node,
								 t_path *second_node)
{
	int		node_hash;
	t_edge	*edge_find;
	t_node	*node_find;

	node_hash = hash(state->nodes_total, first_node->name);
	node_find = state->node_matrix[node_hash];
	while (ft_strcmp(first_node->name, node_find->name) != 0)
		node_find = node_find->other_hash;
	edge_find = node_find->begin_edge;
	while (ft_strcmp(edge_find->name, second_node->name) != 0)
		edge_find = edge_find->next;
	edge_find->weight = -1;
	node_hash = hash(state->nodes_total, second_node->name);
	node_find = state->node_matrix[node_hash];
	while (ft_strcmp(second_node->name, node_find->name) != 0)
		node_find = node_find->other_hash;
	edge_find = node_find->begin_edge;
	while (ft_strcmp(edge_find->name, first_node->name) != 0)
		edge_find = edge_find->next;
	edge_find->use = 0;
}

static void		edges_out(t_state *state, char *name)
{
	int			node_hash;
	t_edge		*ptr;
	t_node		*find_node;

	node_hash = hash(state->nodes_total, name);
	find_node = state->node_matrix[node_hash];
	while (ft_strcmp(name, find_node->name) != 0)
		find_node = find_node->other_hash;
	find_node->node_copy = node_copy(state, find_node);
	ptr = find_node->begin_edge;
	if (!(find_node->node_copy->begin_edge = (t_edge *)malloc(sizeof(t_edge))))
		error(state);
	find_node->node_copy->begin_edge->name = ft_strdup(find_node->name);
	find_node->node_copy->begin_edge->weight = 0;
	find_node->node_copy->begin_edge->next = NULL;
	find_node->node_copy->begin_edge->use = 1;
	while (ptr)
	{
		if (ptr->use && ptr->weight != -1)
		{
			edges_copy(state, find_node->node_copy->begin_edge, ptr);
			ptr->use = 0;
		}
		ptr = ptr->next;
	}
}

void			suurballe(t_state *state)
{
	t_route	*route;
	t_path	*path;

	route = state->solve->routes;
	while (route)
	{
		path = route->path;
		while (path->f)
		{
			edges_inverse(state, path, path->f);
			path = path->f;
		}
		route = route->next;
	}
	route = state->solve->routes;
	while (route)
	{
		path = route->path->f;
		while (path->f)
		{
			edges_out(state, path->name);
			path = path->f;
		}
		route = route->next;
	}
}
