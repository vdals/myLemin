/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symb2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 19:06:07 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:50:38 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_print_symb22(t_arg *r, int sum)
{
	if (r->num != 0 && r->minus == 0)
		sum += ft_size_print(r, 1);
	sum += ft_putchar('%');
	if (r->num != 0 && r->minus == 1)
		sum += ft_size_print_minus(r, 1);
	return (sum);
}

int		ft_print_ptr2(t_arg *r, int sum)
{
	int	i;

	i = 0;
	if (r->num != 0 && r->minus == 0 && r->minus2 == 0 && r->wiedth < sum)
	{
		sum += ft_size_print2(r, sum);
		print_base(r->p, 16);
	}
	else if (r->num != 0 && r->minus == 0 && r->minus2 == 0)
	{
		while (r->num - r->wiedth - 2 - i > 0)
			i += ft_putchar(' ');
		ft_putstr("0x");
		while (r->wiedth - sum + 2 > 0)
			sum += ft_putchar('0');
		print_base(r->p, 16);
	}
	return (sum);
}

int		ft_print_ptr3(t_arg *r, int sum)
{
	if (r->star == 1 && r->p != 0)
	{
		r->fmt++;
		ft_putstr("0x");
		print_base(r->p, 16);
		return (sum);
	}
	else if (r->star == 1 && r->p == 0)
	{
		ft_putstr("0x");
		sum += ft_putchar('0');
		r->fmt++;
		return (sum - 1);
	}
	else
		return (0);
}

int		ft_print_ptr4(t_arg *r, int sum)
{
	if (r->num != 0 && r->minus2 == 1)
	{
		ft_putstr("0x");
		print_base(r->p, 16);
		sum += ft_size_print_minus(r, sum);
	}
	if (r->num != 0 && r->minus == 1 && r->minus2 == 0)
	{
		ft_putstr("0x");
		while (r->wiedth + 2 - sum > 0)
			sum += ft_putchar('0');
		print_base(r->p, 16);
		while (r->num - sum > 0)
			sum += ft_putchar(' ');
	}
	return (sum);
}
