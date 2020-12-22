/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <jnydia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 15:11:16 by jnydia            #+#    #+#             */
/*   Updated: 2020/12/22 15:11:16 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	The found paths are suitable
**	as long as the number of steps
**	of the found path is less than
**	the previous one.
*/

static int		solve_compare(t_state *state)
{
	t_solve *s_tmp;
	t_route *r_tmp;
	t_route *r_ptr;

	if (!state->solve || !state->solve->next)
		return (1);
	else if (state->solve->steps < state->solve->next->steps)
		return (1);
	else
	{
		s_tmp = state->solve;
		r_tmp = s_tmp->routes;
		while (r_tmp)
		{
			r_ptr = r_tmp->next;
			free_route(r_tmp, r_tmp->path);
			r_tmp = r_ptr;
		}
		state->solve = state->solve->next;
		free(s_tmp);
		return (0);
	}
}

static void		extend_ants(t_state *state, t_solve *solve, int max_len)
{
	int		k;
	int		len;
	t_route	*r_tmp;

	len = max_len - 1;
	k = state->ants_total;
	r_tmp = solve->routes;
	while (r_tmp && k > 0 && solve->routes_total != 1)
	{
		if (r_tmp->use)
		{
			r_tmp->ants = (k < max_len - r_tmp->len) ? k : max_len - r_tmp->len;
			k -= r_tmp->ants;
		}
		r_tmp = r_tmp->next;
	}
	len += (k % solve->routes_total == 0) ? k / solve->routes_total : \
											k / solve->routes_total + 1;
	r_tmp = solve->routes;
	while (k-- > 0)
	{
		++r_tmp->ants;
		r_tmp = (r_tmp->next) ? r_tmp->next : solve->routes;
	}
	solve->steps = len;
}

static void		count_steps(t_state *state, t_solve *solve)
{
	int		max_len;
	int		valid_space;
	t_route	*tmp;

	valid_space = 0;
	tmp = solve->routes;
	max_len = tmp->len;
	if (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		if (tmp->len > max_len)
			max_len = tmp->len;
		tmp = tmp->next;
	}
	tmp = solve->routes;
	while (tmp)
	{
		valid_space += max_len - tmp->len;
		tmp = tmp->next;
	}
	extend_ants(state, solve, max_len);
}

/*
**	While we can create optimized paths
**	we get the path thanks to the bs_algo,
**	then we get shortest way and exclude
**	intersections
*/

int				finding_paths(t_state *state)
{
	while (solve_compare(state))
	{
		if (state->solve)
			suurballe(state);
		if (!(bellman_ford(state)))
			break ;
		route_short(state);
		if (!state->solve->next)
			queue_clean(state);
		count_steps(state, state->solve);
	}
	if (!state->solve)
		error(state);
	card_print(state);
	if (state->flag[15] == 1)
		print_routes(state);
	move_ants(state, state->solve->routes, 0);
	return (0);
}
