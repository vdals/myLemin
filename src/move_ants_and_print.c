#include "lem_in.h"

void	card_print(t_state *state)
{
	t_card		*tmp;

	tmp = state->card;
	while (tmp)
	{
		ft_printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("\n");
}

void	print_routes(t_state *state)
{
	int 		i;
	t_path		*tmp;
	t_route		*tmp2;
	t_solve 	*tmp3;

	tmp3 = state->solve;
	tmp2 = tmp3->routes;
	ft_printf("Total roads found %d:\n", tmp3->id);
	while (tmp2)
	{
		ft_printf("Route, with len %d: ", tmp3->routes->len);
		i = tmp3->routes->len - 1;
		tmp = tmp2->path->b;
		while (i >= 0)
		{
			ft_printf("%s -> ", tmp->name);
			tmp = tmp->b;
			i--;
		}
		ft_printf("%s", tmp->name);
		ft_printf("\n");
		tmp2 = tmp2->next;
	}
	ft_printf("\n");
}

static int		finish_not(t_route *routes)
{
	int			rt;
	t_route		*tmp;

	rt = 1;
	tmp = routes;
	while (tmp)
	{
		if (tmp->path->f->ant_name == -1 ||
			(tmp->path->f == tmp->path->b && tmp->ants <= 0))
			rt = 0;
		else
			return (1);
		tmp = tmp->next;
	}
	return (rt);
}

static void		print_path(int ant_name, char *path_name, int n)
{
	if (n)
		write(1, " ", 1);
	ft_printf("L%d-%s", ant_name, path_name);
}

static void		routes_print(t_state *state, int n)
{
	t_path		*path;
	t_route		*route;

	route = state->solve->routes;
	while (route)
	{
		path = route->path;
		while (path->ant_name <= 0 && path->f != route->path->b)
			path = path->f;
		while (path->ant_name > 0)
		{
			print_path(path->ant_name, path->name, n++);
			path = path->f;
		}
		route = route->next;
	}
	write(1, "\n", 1);
}

void			move_ants(t_state *state, t_route *route, int i)
{
	t_path		*pwalk;

	while (finish_not(state->solve->routes))
	{
		route = state->solve->routes;
		while (route)
		{
			pwalk = route->path;
			while (pwalk != route->path->b)
			{
				if (pwalk->f == route->path->b && route->ants > 0)
				{
					pwalk->ant_name = ++i;
					route->ants--;
				}
				else if (pwalk->f == route->path->b && route->ants <= 0)
					pwalk->ant_name = -1;
				else
					pwalk->ant_name = pwalk->f->ant_name;
				pwalk = pwalk->f;
			}
			route = route->next;
		}
		routes_print(state, 0);
	}
}
