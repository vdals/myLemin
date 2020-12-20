#include "lem_in.h"

static void		node_init(t_node *node_lst, char **node_matrix)
{
	node_lst->links = 0;
	node_lst->in_queue = 0;
	node_lst->bfs = 0;
	node_lst->name = ft_strdup(node_matrix[0]);
	node_lst->begin_edge = NULL;
	node_lst->next = NULL;
	node_lst->prev = NULL;
	node_lst->other_hash = NULL;
	node_lst->node_copy = NULL;
	node_lst->queue = NULL;
}

static int		node_check(char **node_matrix)
{
	int i;
	int j;

	i = 0;
	if (!node_matrix[2] || node_matrix[3])
		return (0);
	while (node_matrix[i])
	{
		j = 0;
		while (i > 0 && node_matrix[i][j])
		{
			if (!ft_isdigit(node_matrix[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int		check_repeats(t_node *begin_node, char **node_matrix)
{
	t_node *tmp;

	tmp = begin_node;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, node_matrix[0]))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/*
**	Record node_matrix use structure in (begin_node)
**	variable as is it presented in the card.
**	If we have (s) or (e) point,
**	we also write to the (s) of (e).
*/

static void		node_recording(t_state *state, char **node_matrix, t_coord *point)
{
	t_node *node_lst;

	if (!state->begin_node)
	{
		if (!(state->begin_node = (t_node*)malloc(sizeof(t_node))))
			error(state);
		node_lst = state->begin_node;
	}
	else
	{
		node_lst = state->begin_node;
		while (node_lst->next)
			node_lst = node_lst->next;
		if (!(node_lst->next = (t_node *)malloc(sizeof(t_node))))
			error(state);
		node_lst = node_lst->next;
	}
	node_init(node_lst, node_matrix);
	if (point->start)
		state->s = node_lst;
	if (point->end)
		state->e = node_lst;
	point->start = 0;
	point->end = 0;
}

/*
**	Split the line into 3 parts, because
**	room looks like this (name x y).
**	Checking the room for validity and repeats.
*/

int				save_node(t_state *state, char *line, t_coord *point)
{
	char	**split_line;

	if (state->node_matrix)
		error(state);
	if (!(split_line = ft_strsplit(line, ' ')))
		return (0);
	if (!node_check(split_line) || check_repeats(state->begin_node, split_line))
		error(state);
	node_recording(state, split_line, point);
	state->nodes_total++;
	ft_clean_array(split_line);
	return (1);
}
