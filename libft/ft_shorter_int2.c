/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorter_int2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 18:24:19 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 18:35:49 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		wiedth_help_i2(t_arg *r, int sum)
{
	if (r->space == 1)
		ft_putchar('0');
	if (r->plus == 1 && r->lls >= 0)
		sum += ft_putchar('+');
	if (r->lls < 0)
		ft_putchar('-');
	return (sum);
}

int		helper_i2(t_arg *r, int sum)
{
	if (r->plus == 1 && r->lls >= 0)
		sum += 1;
	if (r->lls < 0 && r->zero == 1)
		ft_putchar('-');
	if (r->lls < 0 && r->point == 1 && \
	r->wiedth >= length_of_num_i(ABS(r->lls), 10))
		ft_putchar('-');
	if (r->lls < 0 && r->point == 1 && \
	r->wiedth > length_of_num_i(ABS(r->lls), 10))
		sum += ft_putchar('0');
	if (r->lls >= 0 && r->space == 1 && r->plus == 0)
		sum += ft_putchar(' ');
	if (r->lls >= 0 && r->plus == 1 && r->zero == 1)
		ft_putchar('+');
	return (sum);
}
