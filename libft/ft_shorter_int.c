/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorter_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:29:36 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 18:39:08 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wiedth_help_i(t_arg *r, int base, int sum)
{
	int		i;

	i = 0;
	if (r->space == 1)
		i = 1;
	if (r->point == 1 && r->wiedth > length_of_num_i(ABS(r->lls), 10) && \
	r->num > r->wiedth && r->lls < 0)
	{
		sum--;
		i++;
	}
	if (r->plus == 0 && r->space == 1 && r->lls > 0)
		sum += ft_putchar(' ');
	while (r->num - r->wiedth - i - r->plus > 0)
		i += ft_putchar(' ');
	sum = wiedth_help_i2(r, sum);
	if (r->point == 1 && r->wiedth == 0 && r->lls == 0)
		return (sum);
	while (r->wiedth - sum + r->plus > 0)
		sum += ft_putchar('0');
	if (r->point == 1 && (r->num == 0 || r->num < r->wiedth) && r->lls < 0)
		sum += ft_putchar('0');
	print_base_i(r->lls, base);
	return (sum + i);
}

static int	helper_i(t_arg *r, int base, int sum)
{
	if (r->wiedth > r->lnint)
		return (wiedth_help_i(r, base, sum));
	sum = helper_i2(r, sum);
	if (r->num == 0 && r->point == 1 && r->wiedth == 0 && r->lls == 0)
		return (sum - 1);
	if (r->num != 0)
		sum += ft_size_print(r, sum);
	if (r->lls >= 0 && r->plus == 1 && r->zero == 0)
		ft_putchar('+');
	if (r->lls < 0 && r->zero == 0 && r->point == 0)
		ft_putchar('-');
	if (r->point == 1 && r->wiedth == 0 && r->lls == 0)
		return (sum + ft_putchar(' ') - 1);
	if (r->lls < -9223372036854775807)
		return (sum + ft_putstr("9223372036854775808") - r->lnint + 1);
	if (r->point == 1 && (r->wiedth < length_of_num_i(ABS(r->lls), 10)) && \
	r->lls < 0)
		ft_putchar('-');
	print_base_i(r->lls, base);
	return (sum);
}

static int	min_sh_i(t_arg *r, int base, int sum)
{
	if (r->star == 1 && r->minus2 == 1 && r->num != 0)
	{
		while (r->num - sum > 0)
			sum += ft_putchar('0');
	}
	r->num = r->wiedth;
	if (r->plus == 0 && r->space == 1 && r->lls > 0)
		sum += ft_putchar(' ');
	if (r->plus == 1 && r->lls >= 0)
		sum += ft_putchar('+');
	if (r->lls < 0)
		ft_putchar('-');
	print_base_i(r->lls, base);
	while (r->num - sum > 0 && r->minus2 == 1 && r->star == 0)
		sum += ft_putchar(' ');
	return (sum);
}

static int	min_shorter_i(t_arg *r, int base, int sum)
{
	int		i;

	i = r->wiedth - length_of_num_i(ABS(r->lls), 10);
	if (r->minus2 == 1)
		return (min_sh_i(r, base, sum));
	if (r->wiedth == 0 && r->lls == 0)
		return (ft_size_print(r, 0));
	if (r->plus == 0 && r->space == 1 && r->lls > 0)
		sum += ft_putchar(' ');
	if (r->plus == 1 && r->lls >= 0)
		sum += ft_putchar('+');
	if (r->lls < 0)
		ft_putchar('-');
	if (r->minus == 1 && r->wiedth != -1)
	{
		while (i-- > 0)
			sum += ft_putchar('0');
	}
	while ((r->num < r->wiedth) && (r->wiedth - sum + r->plus) > 0)
		sum += ft_putchar('0');
	print_base_i(r->lls, base);
	if (r->num != 0)
		sum += ft_size_print_minus(r, sum);
	return (sum);
}

int			shorter_i(t_arg *r, int base, int sum)
{
	r->lls = (long long)(r->i);
	if (r->flg == F_HH)
		r->lls = (long long)(r->hhi);
	else if (r->flg == F_H)
		r->lls = (long long)(r->hi);
	else if (r->flg == F_LL)
		r->lls = (long long)(r->lli);
	else if (r->flg == F_L)
		r->lls = (long long)(r->li);
	r->lnint = length_of_num_i(r->lls, base);
	sum += r->lnint;
	if (r->minus == 1 || r->minus2 == 1)
		return (min_shorter_i(r, base, sum));
	else
		return (helper_i(r, base, sum));
}
