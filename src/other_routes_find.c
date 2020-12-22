/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_routes_find.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <jnydia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:50:58 by jnydia            #+#    #+#             */
/*   Updated: 2020/12/22 14:50:58 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_edge	*in_route_edges_find(t_node *node, int number)
{
	t_edge	*tmp_edge;

	tmp_edge = node->begin_edge;
	while (tmp_edge)
	{
		if (tmp_edge->use_in_routes == 1)
		{
			tmp_edge->use_in_routes = number;
			return (tmp_edge);
		}
		tmp_edge = tmp_edge->next;
	}
	return (NULL);
}

static int		make_paths(t_state *state, t_path **new_path,
											t_edge **next_node)
{
	t_node	*find_node;

	if (!((*new_path)->f = (t_path*)malloc(sizeof(t_path))))
		error(state);
	(*new_path)->f->b = (*new_path);
	(*new_path) = (*new_path)->f;
	(*new_path)->ant_name = 0;
	(*new_path)->name = ft_strdup((*next_node)->name);
	(*new_path)->f = NULL;
	if (ft_strcmp((*next_node)->name, state->s->name) == 0)
		return (0);
	find_node = state->node_matrix[hash(state->nodes_total, (*new_path)->name)];
	while (ft_strcmp((*new_path)->name, find_node->name) != 0)
		find_node = find_node->other_hash;
	*next_node = in_route_edges_find(find_node, 1);
	return (1);
}

void			route_recovery(t_edge *next_node)
{
	while (next_node)
	{
		if (next_node->use_in_routes == -1)
			next_node->use_in_routes = 1;
		next_node = next_node->next;
	}
}

void			find_other_routes(t_state *state, t_edge *next_node)
{
	t_route	*route;
	t_path	*new_path;

	while ((next_node = in_route_edges_find(state->e, -1)))
	{
		state->solve->routes_total++;
		if (!state->solve->routes)
		{
			state->solve->routes = new_route(state);
			route = state->solve->routes;
		}
		else
		{
			route->next = new_route(state);
			route = route->next;
		}
		new_path = route->path;
		while (next_node)
		{
			route->len++;
			if (!make_paths(state, &new_path, &next_node))
				break ;
		}
		route->path->b = new_path;
	}
}
