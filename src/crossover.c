/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crossover.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <jnydia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:00:49 by jnydia            #+#    #+#             */
/*   Updated: 2020/12/22 15:12:48 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		reverse_edge_check(t_state *state, char *node_name, \
													char *edge_name)
{
	int			hash_key;
	t_edge		*edge_find;
	t_node		*node_find;

	hash_key = hash(state->nodes_total, node_name);
	node_find = state->node_matrix[hash_key];
	while (ft_strcmp(node_name, node_find->name) != 0)
		node_find = node_find->other_hash;
	edge_find = node_find->begin_edge;
	while (ft_strcmp(edge_find->name, edge_name) != 0)
		edge_find = edge_find->next;
	if (edge_find->use_in_routes >= 1)
		return (1);
	return (0);
}

void			init_solve(t_solve *solve)
{
	solve->steps = 0;
	solve->next = NULL;
	solve->routes = NULL;
	solve->id = 0;
	solve->routes_total = 0;
}

static void		crossed_edges_remove(t_state *state, t_node *node_find,
										t_edge *edge_find, t_path *path_tmp)
{
	int hash_key;

	edge_find->use = 0;
	edge_find->use_in_routes = 0;
	hash_key = hash(state->nodes_total, path_tmp->f->name);
	node_find = state->node_matrix[hash_key];
	while (ft_strcmp(path_tmp->f->name, node_find->name) != 0)
		node_find = node_find->other_hash;
	edge_find = node_find->begin_edge;
	while (ft_strcmp(edge_find->name, path_tmp->name) != 0)
		edge_find = edge_find->next;
	edge_find->use = 0;
	edge_find->use_in_routes = 0;
}

int				find_crossover(t_state *state, t_route *route)
{
	int			rt;
	t_path		*path_tmp;
	t_node		*node_find;
	t_edge		*edge_find;

	rt = 0;
	path_tmp = route->path;
	while (path_tmp->f)
	{
		node_find = state->node_matrix[hash(state->nodes_total, \
											path_tmp->name)];
		while (ft_strcmp(path_tmp->name, node_find->name) != 0)
			node_find = node_find->other_hash;
		edge_find = node_find->begin_edge;
		while (ft_strcmp(edge_find->name, path_tmp->f->name) != 0)
			edge_find = edge_find->next;
		if (edge_find->use_in_routes > 1 || (edge_find->use_in_routes >= 1\
		&& reverse_edge_check(state, edge_find->name, node_find->name)))
		{
			rt = 1;
			crossed_edges_remove(state, node_find, edge_find, path_tmp);
		}
		path_tmp = path_tmp->f;
	}
	return (rt);
}
