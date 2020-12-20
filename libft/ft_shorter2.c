/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorter2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:23:44 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:42:29 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		m_s_u_i2(t_arg *r, int sum)
{
	r->zero = 1;
	r->num = r->wiedth;
	sum += ft_size_print(r, sum);
	return (sum);
}

int		h1_u_i2(t_arg *r, int base, int sum)
{
	int	lgth;

	lgth = r->wiedth - sum;
	while (r->num - r->wiedth - r->move + check_hash_help(r) > 0)
		r->move += ft_putchar(' ');
	sum += ft_print_hash(r);
	while (lgth-- > 0)
		sum += ft_putchar('0');
	print_base(r->ull, base);
	return (sum + r->move);
}

int		h1_u_i3(t_arg *r, int sum)
{
	r->num -= check_hash_help(r);
	sum += ft_size_print(r, r->wiedth);
	r->zero = 1;
	r->num = r->wiedth;
	sum += ft_size_print(r, 0);
	return (sum - 1);
}

int		h1_u_i4(t_arg *r, int sum)
{
	while (r->num - sum + check_hash_help(r) > 0 && (*(r->fmt + 1) == 'x') \
	&& r->num != r->wiedth)
		sum += ft_putchar(' ');
	while (r->num - sum > 0 && (*(r->fmt + 1) == 'x') && \
	r->num == r->wiedth && r->hsh == 0)
		sum += ft_putchar('0');
	while (r->num - sum + 2 > 0 && (*(r->fmt + 1) == 'x') && \
	r->num == r->wiedth && r->hsh == 1)
		sum += ft_putchar('0');
	return (sum);
}

int		h1_u_i5(t_arg *r, int base, int sum)
{
	if (r->wiedth > sum)
		r->num = r->num - r->wiedth;
	else
		r->num = r->num - sum;
	while (r->num-- > 0)
		sum += ft_putchar(' ');
	r->wiedth = r->wiedth - length_of_num_i(r->u_i, base);
	while (r->wiedth-- > 0)
		sum += ft_putchar('0');
	sum += ft_print_hash(r);
	return (sum);
}
