/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorter_high2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:09:35 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 18:19:02 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		m_s_u_i_high2(t_arg *r, int base, int sum)
{
	int		i;
	int		t;

	i = 0;
	t = 0;
	r->num -= ft_print_hash(r);
	t = r->num;
	r->num = r->wiedth;
	r->zero = 1;
	sum += ft_size_print(r, sum);
	print_base_high(r->ull, base);
	r->zero = 0;
	r->num = t;
	i = length_of_num(r->ull, base);
	if (r->wiedth < i)
		r->wiedth = i;
	if (r->ull == 0 && r->hsh == 1)
		sum -= 2;
	sum += ft_size_print_minus(r, r->wiedth);
	return (sum - check_hash_help(r));
}

int		h1_u_i_high2(t_arg *r, int base, int sum)
{
	int	lgth;
	int	i;

	lgth = r->wiedth - sum;
	i = 0;
	while (r->num - r->wiedth - i + check_hash_help(r) > 0)
		i += ft_putchar(' ');
	sum += ft_print_hash(r);
	while (lgth-- > 0)
		sum += ft_putchar('0');
	print_base_high(r->ull, base);
	return (sum + i);
}

int		h1_u_i_high3(t_arg *r, int sum)
{
	r->num -= check_hash_help(r);
	sum += ft_size_print(r, r->wiedth);
	r->zero = 1;
	r->num = r->wiedth;
	sum += ft_size_print(r, 0);
	return (sum - 1);
}
