/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shorter3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:45:04 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:46:25 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		h1_u_i6(t_arg *r, int base, int sum)
{
	if (r->num != 0 && (*(r->fmt + 1) == 'u' || *(r->fmt + 1) == 'o') && \
	r->wiedth > 0 && r->num > r->wiedth)
		sum = h1_u_i5(r, base, sum);
	else if (r->num != 0 && (*(r->fmt + 1) == 'o' || *(r->fmt + 1) == 'u'))
	{
		r->zero = 1;
		sum += ft_size_print(r, sum);
		sum += ft_print_hash(r);
	}
	if (r->hsh == 1 && *(r->fmt + 1) == 'x' && r->wiedth == 0)
		sum += ft_print_hash(r);
	if (r->hsh == 1 && *(r->fmt + 1) == 'o' && r->wiedth == 0 && \
	r->ull != 0)
		sum += ft_print_hash(r);
	if (r->num != 0 && r->wiedth == 0 && r->ull == 0 && \
	(*(r->fmt + 1) == 'x' || *(r->fmt + 1) == 'o') && r->point == 1)
		ft_putchar(' ');
	else
		print_base(r->ull, base);
	return (sum);
}
