/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:02:05 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:47:47 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	h1_u_i(t_arg *r, int base, int sum)
{
	if (r->num > r->wiedth && r->wiedth - sum > 0 && r->ull != 0)
		return (h1_u_i2(r, base, sum));
	if (r->num > r->wiedth && r->ull == 0 && r->num != 0 && r->wiedth != 0)
		return (h1_u_i3(r, sum));
	if (r->wiedth > r->num)
		r->num = r->wiedth;
	if (r->wiedth == 0 && r->ull == 0 && r->num != 0 && *(r->fmt + 1) == 'u')
		return (ft_size_print(r, 0));
	if (r->hsh == 1 && *(r->fmt + 1) == 'x' && r->wiedth != 0)
		sum += ft_print_hash(r);
	sum = h1_u_i4(r, sum);
	if (r->num != 0 && *(r->fmt + 1) == 'o' && r->wiedth == 0)
	{
		r->zero = 0;
		sum += ft_size_print(r, sum);
		if (r->hsh == 1)
			sum += ft_putchar(' ');
		sum += ft_print_hash(r);
	}
	sum = h1_u_i6(r, base, sum);
	return (sum);
}

static int	helper_u_i(t_arg *r, int base, int sum)
{
	if (r->num == 0 && (r->wiedth == -1 || r->wiedth == 0) && \
	(*(r->fmt + 1) == 'x' || *(r->fmt + 1) == 'u') && r->ull == 0 && \
	r->point == 1)
		return (0);
	if (r->num == 0 && (r->wiedth == -1 || r->wiedth == 0) && \
	*(r->fmt + 1) == 'o' && r->ull == 0 && r->point == 1 && \
	r->hsh == 0)
		return (0);
	if (r->wiedth != -1)
		return (h1_u_i(r, base, sum));
	if (r->hsh == 1 && *(r->fmt + 1) == 'x' && r->zero == 1)
		sum += ft_print_hash(r);
	if (r->num != 0)
		sum += ft_size_print(r, sum);
	if (r->hsh == 1 && *(r->fmt + 1) == 'o' && r->ull > 0)
		sum += ft_print_hash(r);
	if (r->hsh == 1 && *(r->fmt + 1) == 'x' && r->zero != 1)
		sum += ft_print_hash(r);
	if (r->num != 0 && r->wiedth == -1 && r->ull == 0 && \
	*(r->fmt + 1) == 'x' && r->point == 1)
		ft_putchar(' ');
	else
		print_base(r->ull, base);
	return (sum);
}

static int	m_s_u_i(t_arg *r, int base, int sum)
{
	int		i;

	i = 0;
	i += ft_print_hash(r);
	if (r->minus == 1 && r->wiedth < r->num)
	{
		while (r->wiedth - sum > 0)
			sum += ft_putchar('0');
		print_base(r->ull, base);
		while (r->num - sum > 0)
			sum += ft_putchar(' ');
		return (sum);
	}
	if (r->wiedth > r->num && r->minus2 == 0)
		sum = m_s_u_i2(r, sum);
	print_base(r->ull, base);
	if (r->minus2 == 1)
	{
		while (r->wiedth - sum - i > 0)
			sum += ft_putchar(' ');
	}
	return (sum + i);
}

static int	min_shorter_u_i(t_arg *r, int base, int sum)
{
	if (r->wiedth == 0 && r->ull == 0 && r->num != 0 && \
	(*(r->fmt + 1) == 'u' || *(r->fmt + 1) == 'x'))
		return (ft_size_print(r, 0));
	if (r->wiedth != -1)
		return (m_s_u_i(r, base, sum));
	if (r->hsh == 1)
		sum += ft_print_hash(r);
	print_base(r->ull, base);
	if (r->num != 0)
		sum += ft_size_print_minus(r, sum);
	return (sum);
}

int			shorter_u_i(t_arg *r, int base, int sum)
{
	r->ull = (unsigned long long)(r->u_i);
	if (r->flg == F_HH)
		r->ull = (unsigned long long)(r->hha);
	else if (r->flg == F_H)
		r->ull = (unsigned long long)(r->ha);
	else if (r->flg == F_LL)
		r->ull = (unsigned long long)(r->lla);
	else if (r->flg == F_L)
		r->ull = (unsigned long long)(r->la);
	sum += length_of_num(r->ull, base);
	r->move = 0;
	if (r->minus == 1 || r->minus2 == 1)
		return (min_shorter_u_i(r, base, sum));
	else
		return (helper_u_i(r, base, sum));
}
