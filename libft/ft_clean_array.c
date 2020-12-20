#include "libft.h"

void	ft_clean_array(char **array)
{
	int i;

	i = -1;
	while (array[++i] != NULL)
		free(array[i]);
	free(array);
}