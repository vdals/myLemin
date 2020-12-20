#include "lem_in.h"

static void		init_edge(t_edge *edge, char *edge_name)
{
	edge->use = 1;
	edge->use_in_routes = 0;
	edge->next = NULL;
	edge->name = ft_strdup(edge_name);
	edge->weight = 1;
}

static int		new_edge_create(t_state *state, t_node *find_node, char *node_edge)
{
	t_edge *list_edge;

	if (!find_node->begin_edge)
	{
		if (!(find_node->begin_edge = (t_edge*)malloc(sizeof(t_edge))))
			error(state);
		list_edge = find_node->begin_edge;
	}
	else
	{
		list_edge = find_node->begin_edge;
		while (list_edge->next)
		{
			if (ft_strcmp(list_edge->name, node_edge) == 0)
				return (0);
			list_edge = list_edge->next;
		}
		if (ft_strcmp(list_edge->name, node_edge) == 0)
			return (0);
		if (!(list_edge->next = (t_edge*)malloc(sizeof(t_edge))))
			error(state);
		list_edge = list_edge->next;
	}
	init_edge(list_edge, node_edge);
	return (1);
}

static int		add_edge(t_state *state, char *node, char *node_edge)
{
	int		hash_key;
	t_node	*find_node;

	hash_key = hash(state->nodes_total, node);
	find_node = state->node_matrix[hash_key];
	if (!find_node)
		return (0);
	while (find_node && ft_strcmp(find_node->name, node))
		find_node = find_node->other_hash;
	if (!find_node || !(new_edge_create(state, find_node, node_edge)))
		return (0);
	find_node->links++;
	return (1);
}

/*
**	The hash table is created in size (nodes_total * 4).
**	Write down all node_matrix by their hash key position.
**	If we have collision - record in (other_hash) variable.
*/

static void		create_hash_table(t_state *state)
{
	int		hash_key;
	t_node	*last_node_find;
	t_node	*tmp;

	hash_key = -1;
	tmp = state->begin_node;
	if (!(state->node_matrix = (t_node**)malloc(sizeof(t_node*) * (state->nodes_total * 4))))
		error(state);
	while (hash_key < state->nodes_total * 4 - 1)
		state->node_matrix[++hash_key] = NULL;
	while (tmp)
	{
		hash_key = hash(state->nodes_total, tmp->name);
		if (!state->node_matrix[hash_key])
			state->node_matrix[hash_key] = tmp;
		else
		{
			last_node_find = state->node_matrix[hash_key];
			while (last_node_find->other_hash)
				last_node_find = last_node_find->other_hash;
			last_node_find->other_hash = tmp;
		}
		tmp = tmp->next;
	}
}

/*
**	Split line into 2 parts, because
**	link looks like this (room1-room2).
**	Creating hash_table in (node_matrix) variable.
*/

int				save_edges(t_state *state, char *line)
{
	char	**split_line;

	if (!(split_line = ft_strsplit(line, '-')))
		error(state);
	if (ft_strchr(split_line[0], ' ') || ft_strchr(split_line[1], ' ') ||
		!state->begin_node)
		error(state);
	if (!state->node_matrix)
		create_hash_table(state);
	if (!(add_edge(state, split_line[0], split_line[1])))
	{
		ft_clean_array(split_line);
		return (0);
	}
	if (!(add_edge(state, split_line[1], split_line[0])))
	{
		ft_clean_array(split_line);
		return (0);
	}
	ft_clean_array(split_line);
	return (1);
}
