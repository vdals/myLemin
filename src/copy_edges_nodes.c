#include "lem_in.h"

t_node		*node_copy(t_state *state, t_node *original)
{
	t_node	*copy;

	if (!(copy = (t_node*)malloc(sizeof(t_node))))
		error(state);
	copy->name = ft_strdup(original->name);
	copy->next = NULL;
	copy->queue = NULL;
	copy->in_queue = 0;
	copy->bfs = 0;
	copy->begin_edge = NULL;
	copy->other_hash = NULL;
	copy->node_copy = NULL;
	copy->links = original->links;
	copy->prev = NULL;
	return (copy);
}

t_edge		*edges_copy(t_state *state, t_edge *edge_copy,
						  t_edge *orig_edge)
{
	t_edge	*tmp;

	tmp = edge_copy;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = (t_edge *)malloc(sizeof(t_edge))))
		error(state);
	tmp = tmp->next;
	tmp->name = ft_strdup(orig_edge->name);
	tmp->weight = orig_edge->weight;
	tmp->use = 1;
	tmp->next = NULL;
	return (tmp);
}
