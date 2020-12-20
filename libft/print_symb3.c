/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symb3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:52:08 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:53:15 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_str2(t_arg *r, int sum)
{
	if (r->num != 0 && ft_strlen(r->s) == 0 && r->minus == 1 && r->s != NULL)
	{
		r->fmt++;
		return (ft_size_print(r, 0));
	}
	else if ((r->num != 0) && (r->s != NULL) && r->minus == 1)
		sum += ft_size_print_minus(r, r->wiedth);
	else if (r->num != 0 && r->s == NULL && r->minus == 1 && r->wiedth > 6)
		sum += ft_size_print_minus(r, 6);
	else if (r->num != 0 && r->s == NULL && r->minus == 1)
		sum += ft_size_print_minus(r, r->wiedth);
	r->fmt++;
	return (sum);
}

int		ft_print_str3(t_arg *r, int sum)
{
	if (r->num != 0 && ft_strlen(r->s) == 0 && r->minus == 0 && r->s != NULL)
		return (ft_size_print(r, 0));
	else if (r->num != 0 && (r->s != NULL) && r->minus == 0)
		sum += ft_size_print(r, r->wiedth);
	else if (r->num != 0 && r->s == NULL && r->minus == 0)
		sum += ft_size_print(r, r->wiedth);
	if (ft_strlen(r->s) == 0 && r->num != 0 && r->s != NULL)
		sum += 0;
	else if (r->s == NULL && r->wiedth <= 6)
		sum += ft_putstr3("(null)", r->wiedth);
	else if (r->s == NULL && r->wiedth > 6)
		sum += ft_putstr("(null)");
	else if (ft_strlen(r->s) == 0 && r->num == 0)
		return (sum);
	else if (r->num == 0 && r->point == 1 && r->wiedth > 0 && \
	r->wiedth > (int)ft_strlen(r->s))
		sum += ft_putstr(r->s);
	else if (r->num != 0 && r->point == 1 && r->wiedth > (int)ft_strlen(r->s))
		sum += ft_putstr(r->s);
	else
		sum += ft_putstr3(r->s, r->wiedth);
	return (sum);
}

int		ft_print_str4(t_arg *r)
{
	r->fmt++;
	return (ft_putchar(' '));
}
