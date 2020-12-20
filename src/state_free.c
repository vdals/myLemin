#include "lem_in.h"

void	card_free(t_card *card)
{
	t_card	*tmp;

	while (card)
	{
		tmp = card->next;
		free(card->content);
		free(card);
		card = tmp;
	}
}

void	edges_free(t_edge *edges)
{
	t_edge	*e_ptr;

	while (edges)
	{
		e_ptr = edges->next;
		free(edges->name);
		free(edges);
		edges = e_ptr;
	}
}

void	free_route(t_route *tmp_route, t_path *tmp_path)
{
	t_path	*p_ptr;

	p_ptr = tmp_path;
	while (tmp_path)
	{
		p_ptr = tmp_path->f;
		free(tmp_path->name);
		free(tmp_path);
		tmp_path = p_ptr;
	}
	free(tmp_route);
}

void	solve_free(t_solve *solve)
{
	t_route	*route_tmp;
	t_route	*r_ptr;
	t_solve	*sol_tmp;
	t_solve	*s_ptr;

	sol_tmp = solve;
	while (sol_tmp)
	{
		route_tmp = sol_tmp->routes;
		while (route_tmp)
		{
			r_ptr = route_tmp->next;
			free_route(route_tmp, route_tmp->path);
			route_tmp = r_ptr;
		}
		s_ptr = sol_tmp->next;
		free(sol_tmp);
		sol_tmp = s_ptr;
	}
}

void	node_list_free(t_node **node_matrix)
{
	t_node	*tmp;

	while (*node_matrix)
	{
		tmp = (*node_matrix)->next;
		free((*node_matrix)->name);
		if ((*node_matrix)->node_copy)
		{
			edges_free((*node_matrix)->node_copy->begin_edge);
			free((*node_matrix)->node_copy->name);
			free((*node_matrix)->node_copy);
		}
		edges_free((*node_matrix)->begin_edge);
		free((*node_matrix));
		(*node_matrix) = tmp;
	}
}
