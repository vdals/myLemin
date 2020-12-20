
/*
**	Create unique hash key.
**	For example: name - "lem"
**	key - 30;
*/
#include "lem_in.h"

int		hash(int size, char *name)
{
	int i;
	int key;

	i = 0;
	key = 0;
	while (name[i])
	{
		key += name[i];
		i++;
	}
	key = key % (size * 4);
	return (key);
}

void	error(t_state *state)
{
	if (state)
		state_free(state);
	ft_putstr_fd("ERROR\n", 2);
	exit(0);
}

void	ft_getopt(t_state *state, int *ac, char ***av)
{
	int	j;
	int flag;

	flag = 0;
	(*ac)--;
	(*av)++;
	j = 0;
	while ((**av)[++j] && (**av)[j] >= 'a' && (**av)[j] <= 'z')
	{
		if ((**av)[j] == 'h')
			error(state);
		if ((**av)[j] == 'f' && state->flag['f' - 'a'] == 0)
			flag = 1;
		state->flag[(**av)[j] - 'a'] = 1;
	}
	if ((**av)[j])
		error(state);
	if (flag)
	{
		(*av)++;
		(*ac)--;
		if ((state->fd = open((**av), O_RDONLY)) < 1)
			error(state);
	}
}
