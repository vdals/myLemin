#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/libft.h"
//# include "errno.h"
//# include "stdio.h"

typedef struct		s_coord
{
	int				start;
	int				end;
}					t_coord;

typedef struct		s_edge
{
	char			*name;
	int				weight;
	int				use;
	int				use_in_routes;
	struct s_edge	*next;
}					t_edge;

typedef struct		s_node
{
	char			*name;
	int				links;
	int				in_queue;
	int				bfs;
	t_edge			*begin_edge;
	struct s_node	*other_hash;
	struct s_node	*node_copy;
	struct s_node	*queue;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct		s_path
{
	char			*name;
	int				ant_name;
	struct s_path	*f;
	struct s_path	*b;
}					t_path;

typedef struct		s_route
{
	int				len;
	int				ants;
	int				use;
	struct s_route	*next;
	t_path			*path;
}					t_route;

typedef struct		s_solve
{
	int				id;
	int				routes_total;
	int				steps;
	t_route			*routes;
	struct s_solve	*next;
}					t_solve;

typedef struct		s_card
{
	char			*content;
	struct s_card	*next;
}					t_card;

typedef struct		s_state
{
	int				ants_total;
	int				nodes_total;
	int 			flag[32];
	int 			fd;
	t_card			*card;
	t_node			*begin_node;
	t_node			*s;
	t_node			*e;
	t_node			**node_matrix;
	t_solve			*solve;
}					t_state;

int					find_crossover(t_state *state, t_route *route);
int					save_node(t_state *state, char *line, t_coord *point);
int					save_edges(t_state *state, char *line);
int					hash(int size, char *name);
int					parsing(t_state *state);
int					bellman_ford(t_state *state);
int					finding_paths(t_state *state);
int					check_copy(t_node *current_node, char *edge_name);
void				ft_getopt(t_state *state, int *ac, char ***av);
void				print_routes(t_state *state);
void				init_solve(t_solve *solve);
void				card_print(t_state *state);
void				move_ants(t_state *state, t_route *route, int i);
void				node_list_free(t_node **node_matrix);
void				edges_free(t_edge *edges);
void				solve_free(t_solve *solve);
void				card_free(t_card *card);
void				state_free(t_state *state);
void				error(t_state *state);
void				graph_recovery(t_state *state, t_solve *prev_solve);
void				free_route(t_route *tmp_route, t_path *tmp_path);
void				find_other_routes(t_state *state, t_edge *next_node);
void				route_recovery(t_edge *next_node);
void				suurballe(t_state *state);
void				route_short(t_state *state);
void				queue_clean(t_state *state);
void				delete_copy(t_node *node);
void				add_to_queue(t_state *state, t_node *next_for_q,
								t_node *current_node, t_edge *node_edges);
t_route				*new_route(t_state *state);
t_node				*node_copy(t_state *state, t_node *original);
t_edge				*edges_copy(t_state *state, t_edge *edge_copy,
								  t_edge *orig_edge);


#endif
