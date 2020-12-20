/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 18:37:22 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/13 16:12:40 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flagging_float(t_arg *r, va_list ap, int ret, int i)
{
	if (ret == F_LD)
		r->ld = va_arg(ap, long double);
	else if (ret == F_L)
		r->lf = va_arg(ap, double);
	else
		r->f = va_arg(ap, double);
	r->fmt = r->fmt + i + r->move;
	return (ret);
}

static int	ft_c_float(t_arg *r, int i)
{
	r->move = 0;
	while (*(r->fmt + i + r->move) == ' ')
	{
		r->move++;
		r->space = 1;
	}
	if (*(r->fmt + i + r->move) == 'f')
		return (1);
	else
		return (0);
}

int			ft_shorter_f(t_arg *r, va_list ap, int ret)
{
	if (*(r->fmt + 1) == 'L' && ft_c_float(r, 2) != 0)
		ret = flagging_float(r, ap, F_LD, 1);
	else if (*(r->fmt + 1) == 'l' && ft_c_float(r, 2) != 0)
		ret = flagging_float(r, ap, F_L, 1);
	else if (ft_c_float(r, 1) != 0)
		ret = flagging_float(r, ap, 0, 0);
	return (ret);
}
