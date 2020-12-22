/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <jnydia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 14:58:11 by jnydia            #+#    #+#             */
/*   Updated: 2020/12/22 14:58:12 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	If comment have "##s" or "##e" we make
**	point for {save_node} function to save the pointer
**	use room in s variables or e in general structure
*/

static int			save_point(t_state *state, char *line, t_coord *point)
{
	if (point->start == 1 || point->end == 1)
		return (0);
	if (ft_strncmp("##s", line, 3) == 0)
	{
		if (state->s)
			return (0);
		point->start = 1;
	}
	if (ft_strncmp("##e", line, 3) == 0)
	{
		if (state->e)
			return (0);
		point->end = 1;
	}
	return (1);
}

static void			card_save(t_state *state, char *line)
{
	t_card *add_line;
	t_card *card_tmp;

	if (!state->card)
	{
		if (!(card_tmp = (t_card*)malloc(sizeof(t_card))))
			error(state);
		card_tmp->content = ft_strdup(line);
		card_tmp->next = NULL;
		state->card = card_tmp;
	}
	else
	{
		card_tmp = state->card;
		while (card_tmp->next)
			card_tmp = card_tmp->next;
		if (!(add_line = (t_card*)malloc(sizeof(t_card))))
			error(state);
		add_line->content = ft_strdup(line);
		add_line->next = NULL;
		card_tmp->next = add_line;
	}
}

static int			check_ants(t_state *state, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) || (i == 0 && line[i] == 48) ||
			!ft_atoi(line))
			return (0);
		++i;
	}
	state->ants_total = ft_atoi(line);
	if (!state->ants_total)
		error(state);
	return (1);
}

/*
**	At the first entry into the function
**	we write down the number of ants.
**	Then we check for the presence of comment,
**	room or link signs in the line.
*/

static void			parsing_card(t_state *state, char *line, t_coord *point)
{
	int rt;

	rt = 1;
	if (!state->card)
		rt = check_ants(state, line);
	else if (ft_strstr(line, "#"))
		rt = save_point(state, line, point);
	else if (!ft_strstr(line, "-") && !ft_strstr(line, "##"))
		rt = save_node(state, line, point);
	else
		rt = save_edges(state, line);
	card_save(state, line);
	if (!rt)
		error(state);
}

/*
**	Read card with GNL and fill general structure
*/

int					parsing(t_state *state)
{
	int			gnl;
	char		*line;
	t_coord		point;

	point.start = 0;
	point.end = 0;
	while ((gnl = get_next_line(0, &line)) > 0)
	{
		if (*line == '\0' || *line == '\n')
			break ;
		parsing_card(state, line, &point);
		ft_strdel(&line);
	}
	if (gnl < 0)
		error(state);
	free(line);
	if (!state->begin_node || !state->s || !state->e || !state->s->begin_edge
		|| !state->e->begin_edge)
		error(state);
	return (1);
}
