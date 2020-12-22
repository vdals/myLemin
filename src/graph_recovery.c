/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_recovery.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <jnydia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:20:32 by jnydia            #+#    #+#             */
/*   Updated: 2020/12/22 14:20:32 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void			queue_clean(t_state *state)
{
	t_node *next;
	t_node *tmp;

	tmp = state->s;
	while (tmp)
	{
		next = tmp->queue;
		tmp->prev = NULL;
		tmp->queue = NULL;
		tmp->in_queue = 0;
		tmp->bfs = 0;
		tmp = next;
	}
}

void			graph_recovery(t_state *state, t_solve *prev_solve)
{
	int		hash_key;
	t_path	*path_tmp;
	t_node	*node_find;
	t_route	*route_tmp;

	route_tmp = prev_solve->routes;
	while (route_tmp)
	{
		path_tmp = route_tmp->path;
		while (path_tmp)
		{
			hash_key = hash(state->nodes_total, path_tmp->name);
			node_find = state->node_matrix[hash_key];
			while (ft_strcmp(path_tmp->name, node_find->name) != 0)
				node_find = node_find->other_hash;
			delete_copy(node_find);
			path_tmp = path_tmp->f;
		}
		route_tmp = route_tmp->next;
	}
}

void			delete_copy(t_node *node)
{
	t_edge *help;
	t_edge *edge_del;
	t_edge *edge_tmp;

	if (node->node_copy)
	{
		edge_del = node->node_copy->begin_edge;
		while (edge_del)
		{
			help = edge_del->next;
			free(edge_del->name);
			free(edge_del);
			edge_del = help;
		}
		free(node->node_copy->name);
		free(node->node_copy);
		node->node_copy = NULL;
	}
	edge_tmp = node->begin_edge;
	while (edge_tmp)
	{
		edge_tmp->weight = 1;
		edge_tmp->use = 1;
		edge_tmp = edge_tmp->next;
	}
}

int				check_copy(t_node *current_node, char *edge_name)
{
	t_edge *edge_tmp;

	edge_tmp = current_node->begin_edge;
	while (edge_tmp)
	{
		if (ft_strcmp(edge_name, edge_tmp->name) == 0)
			break ;
		edge_tmp = edge_tmp->next;
	}
	if (edge_tmp->use == 0)
		return (1);
	else
		return (0);
}
