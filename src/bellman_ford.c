#include "lem_in.h"

/*
**	Add to the queue all node_matrix
**	that are associated with the current
*/

static void		next_node_for_queue(t_state *state, t_node *current_node)
{
	t_node *next_for_q;
	t_edge *cur_node_edge;

	next_for_q = current_node;
	while (next_for_q->queue)
		next_for_q = next_for_q->queue;
	cur_node_edge = current_node->begin_edge;
	while (cur_node_edge)
	{
		add_to_queue(state, next_for_q, current_node, cur_node_edge);
		if (next_for_q->queue)
			next_for_q = next_for_q->queue;
		cur_node_edge = cur_node_edge->next;
	}
}

/*
**	If all node_matrix be in queue - loop is break.
*/

static int		status_queue(t_node *begin)
{
	while (begin)
	{
		if (begin->in_queue == 0)
			return (0);
		begin = begin->next;
	}
	return (1);
}

/*
**	Add the room to the queue and save the link
**	to the current node in the variable (prev).
**	For example: we have s <- n <- n <- e.
*/

void			add_to_queue(t_state *state, t_node *next_for_q,
								t_node *current_node, t_edge *node_edges)
{
	int		hash_key;
	t_node	*find_node;

	hash_key = hash(state->nodes_total, node_edges->name);
	find_node = state->node_matrix[hash_key];
	while (ft_strcmp(node_edges->name, find_node->name) != 0)
		find_node = find_node->other_hash;
	if (node_edges->weight == -1 &&
		ft_strcmp(node_edges->name, state->s->name) != 0 &&
		ft_strcmp(node_edges->name, state->e->name) != 0)
		find_node = find_node->node_copy;
	if (find_node->in_queue == 0 && node_edges->use)
	{
		next_for_q->queue = find_node;
		find_node->prev = current_node;
		if (!current_node->prev)
			find_node->bfs = node_edges->weight;
		else
			find_node->bfs = find_node->prev->bfs +
							 node_edges->weight;
		next_for_q = next_for_q->queue;
		next_for_q->in_queue = 1;
	}
}

/*
**	We fill the queue and walk through it until
**	e is reached.
*/

int				bellman_ford(t_state *state)
{
	t_node *queue_tmp;

	queue_tmp = state->s;
	queue_tmp->in_queue = 1;
	while (!status_queue(state->begin_node))
	{
		next_node_for_queue(state, queue_tmp);
		queue_tmp->in_queue = -1;
		if (!queue_tmp->queue && state->e->in_queue == 0)
			return (0);
		else if (!queue_tmp->queue && state->e->in_queue != 0)
			return (1);
		queue_tmp = queue_tmp->queue;
	}
	return (1);
}
