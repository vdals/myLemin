/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 14:20:08 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:52:33 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_prints_symb_help(t_arg *r, va_list ap, int sum)
{
	r->c = va_arg(ap, int);
	if (r->c == 0 && r->num == 0)
		return (ft_putchar(0));
	if (r->num == 0 && r->point == 1)
		return (ft_putchar(r->c));
	if (r->wiedth > 0)
		r->num = r->wiedth;
	if (r->num != 0 && r->minus == 0)
		sum += ft_size_print(r, 1);
	sum += ft_putchar(r->c);
	if (r->num != 0 && r->minus == 1)
		sum += ft_size_print_minus(r, 1);
	return (sum);
}

static int		ft_print_str(t_arg *r, int sum)
{
	if (r->wiedth != 0 && r->num != 0 && r->s != NULL && \
	r->wiedth > (int)ft_strlen(r->s))
		r->wiedth = (int)ft_strlen(r->s);
	if (r->s != NULL && ft_strlen(r->s) < (size_t)r->wiedth && r->star == 1)
	{
		r->fmt++;
		return (ft_putstr3(r->s, ft_strlen(r->s)));
	}
	else if (r->star == 1 && r->s != NULL && r->minus2 == 1)
	{
		r->fmt++;
		return (ft_putstr(r->s) + ft_size_print_minus(r, ft_strlen(r->s)));
	}
	else if (r->star == 1 && r->s == NULL && r->minus2 == 1)
	{
		r->fmt++;
		return (ft_putstr("(null)"));
	}
	if (r->minus2 == 1)
		return (ft_print_str4(r));
	sum = ft_print_str3(r, sum);
	if (r->num != 0)
		return (ft_print_str2(r, sum));
	r->fmt++;
	return (sum);
}

int				ft_print_symb(t_arg *r, va_list ap)
{
	int			sum;

	sum = 0;
	if (*(r->fmt + 1) == 'c')
		sum += ft_prints_symb_help(r, ap, sum);
	else if (*(r->fmt + 1) == 's')
	{
		r->s = va_arg(ap, char*);
		if (r->wiedth != -1)
			return (ft_print_str(r, 0));
		if ((r->num != 0) && (r->s != NULL) && r->minus == 0)
			sum += ft_size_print(r, ft_strlen(r->s));
		else if (r->num != 0 && r->s == NULL && r->minus == 0)
			sum += ft_size_print(r, 6);
		if (r->s == NULL)
			sum += ft_putstr("(null)");
		else
			sum += ft_putstr(r->s);
		if ((r->num != 0) && (r->s != NULL) && r->minus == 1)
			sum += ft_size_print_minus(r, ft_strlen(r->s));
		else if (r->num != 0 && r->s == NULL && r->minus == 1)
			sum += ft_size_print_minus(r, 6);
	}
	r->fmt++;
	return (sum);
}

static int		ft_print_ptr(t_arg *r, int sum)
{
	int			i;

	i = 0;
	if ((r->num > r->wiedth) && r->minus2 == 1)
		r->num = r->wiedth;
	if (r->star == 1)
		return (ft_print_ptr3(r, sum));
	if (r->num == 0 && r->point == 1)
	{
		r->fmt++;
		ft_putstr("0x");
		while (r->wiedth - i > 0)
			i += ft_putchar('0');
		return (2 + i);
	}
	if (r->num != 0)
		sum = ft_print_ptr4(r, sum);
	if (r->num != 0 && r->minus == 0 && r->minus2 == 0)
		sum = ft_print_ptr2(r, sum);
	r->fmt++;
	return (sum + i);
}

int				ft_print_symb2(t_arg *r, va_list ap)
{
	int			sum;

	sum = 0;
	if (*(r->fmt + 1) == '%')
		sum = ft_print_symb22(r, sum);
	if (*(r->fmt + 1) == 'p')
	{
		r->p = va_arg(ap, long int);
		sum += 2 + length_of_num(r->p, 16);
		if (r->wiedth != -1)
			return (ft_print_ptr(r, sum));
		if (r->num != 0 && r->minus == 0)
			sum += ft_size_print2(r, sum);
		else
			ft_putstr("0x");
		print_base(r->p, 16);
		if (r->num != 0 && r->minus == 1)
			sum += ft_size_print_minus(r, sum);
	}
	r->fmt++;
	return (sum);
}
