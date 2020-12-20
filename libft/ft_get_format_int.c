/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:56:58 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/10 18:37:07 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flagging_i(t_arg *r, va_list ap, int ret, int i)
{
	if (ret == F_HH)
		r->hhi = (char)va_arg(ap, int);
	else if (ret == F_H)
		r->hi = (short)va_arg(ap, int);
	else if (ret == F_LL)
		r->lli = va_arg(ap, long long);
	else if (ret == F_L)
		r->li = va_arg(ap, long);
	else
		r->i = va_arg(ap, int);
	r->fmt = r->fmt + i + r->move;
	return (ret);
}

static int	ft_c_i(t_arg *r, int i)
{
	r->move = 0;
	while (*(r->fmt + i + r->move) == ' ')
	{
		r->move++;
		r->space = 1;
	}
	if (*(r->fmt + i + r->move) == 'i' || *(r->fmt + i + r->move) == 'd')
		return (1);
	else
		return (-1);
}

int			ft_shorter_i(t_arg *r, va_list ap, int ret)
{
	if (*(r->fmt + 1) == 'h' && *(r->fmt + 2) == 'h' && ft_c_i(r, 3) == 1)
		ret = flagging_i(r, ap, F_HH, 2);
	else if (*(r->fmt + 1) == 'h' && ft_c_i(r, 2) == 1)
		ret = flagging_i(r, ap, F_H, 1);
	else if (*(r->fmt + 1) == 'l' && *(r->fmt + 2) == 'l' && ft_c_i(r, 3) == 1)
		ret = flagging_i(r, ap, F_LL, 2);
	else if (*(r->fmt + 1) == 'l' && ft_c_i(r, 2) == 1)
		ret = flagging_i(r, ap, F_L, 1);
	else if (ft_c_i(r, 1) == 1)
		ret = flagging_i(r, ap, 5, 0);
	return (ret);
}
