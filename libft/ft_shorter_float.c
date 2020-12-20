/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorter_float.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:07:23 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/21 15:52:44 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		shortik_float(t_arg *r, int sum)
{
	if (r->space == 1)
		sum += ft_putchar(' ');
	while (r->num - (r->l1 + r->l2 + 1 + r->plus) - sum > 0)
		sum += ft_putchar(' ');
	if (r->space2 == 1)
	{
		while (r->num - r->l1 - sum > 0)
			sum += ft_putchar(' ');
	}
	if (r->plus == 1)
		sum += ft_putchar('+');
	if (r->precision == 0)
		sum += ft_putstr2(r->fstr, r->l1);
	else if (r->space2 == 1)
		sum += ft_putstr2(r->fstr, r->l1);
	else
		sum += ft_putstr(r->fstr);
	return (sum);
}

static int		min_short_float(t_arg *r, int sum)
{
	if (r->minus2 == 1 && r->wiedth != -1)
	{
		r->num = r->wiedth;
		r->precision = 0;
	}
	else if (r->minus2 == 1)
		r->precision = 0;
	if (r->space2 == 1 || r->space == 1)
		sum += ft_putchar(' ');
	if (r->precision == 0)
		sum += ft_putstr2(r->fstr, r->l1);
	else
		sum += ft_putstr(r->fstr);
	while (r->num - sum > 0 && (r->minus == 1 || r->minus2 == 1))
		sum += ft_putchar(' ');
	return (sum);
}

static void		trolling(t_arg *r)
{
	if (r->i_h == 1)
	{
		r->tail = 0;
		r->l2 = r->precision;
	}
	else if (r->precision < length_of_num_i(r->head, 10))
	{
		r->tail = r->i_h;
		r->l2 = r->precision;
	}
	else if (r->i_h != 0)
	{
		r->tail = ((9 * (r->i_h / ABS(r->i_h)) + r->i_h) / 10) * 10;
		r->l2 = r->precision;
	}
}

static int		ft_ldtoa(t_arg *r, int sum)
{
	r->head = (long)(r->ldd);
	r->tail = r->ldd - (long double)(r->head);
	r->l1 = length_of_num_i(r->head, 10);
	r->i_h = ABS((long)((r->tail) * ft_pow(10, r->precision)));
	trolling(r);
	r->fstr = ft_ltoa(r->l1 + r->l2 + 2, r);
	if (r->num == 0 && r->precision == 0)
	{
		print_base_i(r->head, 10);
		return (r->l1);
	}
	if (r->minus == 1 || r->minus2 == 1)
		return (min_short_float(r, sum));
	else
		return (shortik_float(r, sum));
}

int				shorter_f(t_arg *r, int sum)
{
	if (r->wiedth != -1)
		r->precision = r->wiedth;
	r->ldd = (long double)(r->f);
	if (r->flg == F_L)
		r->ldd = (long double)(r->lf);
	else if (r->flg == F_LD)
		r->ldd = r->ld;
	sum += ft_ldtoa(r, sum);
	free(r->fstr);
	return (sum);
}
