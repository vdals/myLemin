#include "lem_in.h"

void	init_struct(t_state *state)
{
	ft_memset(state->flag, 0, sizeof(int) * 32);
	state->card = NULL;
	state->begin_node = NULL;
	state->s = NULL;
	state->e = NULL;
	state->node_matrix = NULL;
	state->solve = NULL;
	state->ants_total = 0;
	state->nodes_total = 0;
	state->fd = 0;
}

void	state_free(t_state *state)
{
	int 	i;

	i = 0;
	if (state)
		if (state->card)
			card_free(state->card);
	if (state->begin_node)
		node_list_free(&state->begin_node);
	if (state->node_matrix)
		free(state->node_matrix);
	if (state->solve)
		solve_free(state->solve);
	free(state);
}

/*
**	Two main parts of program:
**	parsing - filling (lem) structure
**	and finding_paths, that running the algorithm
*/

int		main(int argc, char **argv)
{
	t_state	*state;

	if (!(state = (t_state*)malloc(sizeof(t_state))))
		error(state);
	init_struct(state);
	while (argc > 1 && argv[1][0] == '-')
		ft_getopt(state, &argc, &argv);
	if (!parsing(state))
		error(state);
	finding_paths(state);
	state_free(state);
	return (0);
}
