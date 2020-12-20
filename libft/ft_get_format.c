/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 17:38:59 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/10 18:37:18 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	flagging(t_arg *r, va_list ap, int ret, int i)
{
	if (ret == F_HH)
		r->hha = (unsigned char)va_arg(ap, int);
	else if (ret == F_H)
		r->ha = (unsigned short)va_arg(ap, int);
	else if (ret == F_LL)
		r->lla = va_arg(ap, unsigned long long int);
	else if (ret == F_L)
		r->la = va_arg(ap, unsigned long int);
	else
		r->u_i = va_arg(ap, unsigned int);
	r->fmt = r->fmt + i + r->move;
	return (ret);
}

static int	ft_c_l(t_arg *r, int i)
{
	r->move = 0;
	while (*(r->fmt + i + r->move) == ' ')
	{
		r->move++;
		r->space = 1;
	}
	if (*(r->fmt + i + r->move) == 'i' || *(r->fmt + i + r->move) == 'l' || \
	*(r->fmt + i + r->move) == 'h' || *(r->fmt + i + r->move) == 'd' || \
	*(r->fmt + i + r->move) == 'f' || *(r->fmt + i + r->move) == 'L')
		return (0);
	else
		return (1);
}

static int	ft_shorter_not_i(t_arg *r, va_list ap, int ret)
{
	if (*(r->fmt + 1) == 'h' && *(r->fmt + 2) == 'h' && ft_c_l(r, 3) != 0)
		ret = flagging(r, ap, F_HH, 2);
	else if (*(r->fmt + 1) == 'h' && ft_c_l(r, 2) != 0)
		ret = flagging(r, ap, F_H, 1);
	else if (*(r->fmt + 1) == 'l' && *(r->fmt + 2) == 'l' && ft_c_l(r, 3) != 0)
		ret = flagging(r, ap, F_LL, 2);
	else if (*(r->fmt + 1) == 'l' && ft_c_l(r, 2) != 0)
		ret = flagging(r, ap, F_L, 1);
	else if (*(r->fmt + 1) != 'i' && ft_c_l(r, 1) != 0 && *(r->fmt + 1) != 'd')
		ret = flagging(r, ap, 5, 0);
	return (ret);
}

int			get_flag(t_arg *r, va_list ap, int ret)
{
	if (*(r->fmt + 1) == 'c' || *(r->fmt + 1) == 's' || \
	*(r->fmt + 1) == 'p' || *(r->fmt + 1) == '%')
		return (0);
	ret = ft_shorter_not_i(r, ap, 0);
	if (ret == 0)
		ret = ft_shorter_i(r, ap, -1);
	if (ret == -1)
		ret = ft_shorter_f(r, ap, 0);
	return (ret);
}
