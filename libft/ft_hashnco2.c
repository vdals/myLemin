/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnco2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:53:19 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 17:55:47 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_minus(t_arg *r)
{
	if (*(r->fmt + 1) == '-')
	{
		while (*(r->fmt + 1) == '-')
			r->fmt++;
		return (1);
	}
	else
		return (0);
}

int		ft_check_star(va_list ap, t_arg *r)
{
	if (*(r->fmt + 1) == '*')
	{
		if (r->point == 0)
		{
			r->num = va_arg(ap, int);
			if (r->num < 0)
			{
				r->minus = 1;
				r->num *= -1;
			}
		}
		else
		{
			r->wiedth = va_arg(ap, int);
			if (r->wiedth < 0)
			{
				r->minus2 = 1;
				r->wiedth *= -1;
			}
		}
		r->fmt++;
	}
	return (1);
}

void	ft_check_wiedth(t_arg *r)
{
	if (*(r->fmt + 1) == '.')
	{
		r->point = 1;
		r->fmt++;
		r->space2 = ft_check_space(r);
		if (r->space2 == 1 && r->num == 0)
		{
			r->minus2 = ft_check_minus(r);
			r->zero = ft_check_zero(r);
			r->num = ft_check_num(r);
		}
		else if (r->space2 == 1 && r->num != 0)
		{
			r->minus2 = ft_check_minus(r);
			r->zero = ft_check_zero(r);
		}
		else
		{
			r->minus2 = ft_check_minus(r);
			r->zero = ft_check_zero(r) - 1;
			r->wiedth = ft_check_num(r);
		}
	}
}

int		ft_check_undefined_behavior(t_arg *r)
{
	while (*(r->fmt + 1) != 'h' || *(r->fmt + 1) != 'l' || \
	*(r->fmt + 1) != 'c' || *(r->fmt + 1) != 's' || \
	*(r->fmt + 1) != 'p' || *(r->fmt + 1) != 'x' || \
	*(r->fmt + 1) != 'X' || *(r->fmt + 1) != '%' || \
	*(r->fmt + 1) != 'o' || *(r->fmt + 1) != 'u' || \
	*(r->fmt + 1) != 'i' || *(r->fmt + 1) != 'd' || \
	*(r->fmt + 1) != 'f')
		r->fmt++;
	return (1);
}
