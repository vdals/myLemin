/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 17:49:57 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/21 16:30:09 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_print_base(t_arg *r, int sum)
{
	if (*(r->fmt + 1) == 'o')
		sum += shorter_u_i(r, 8, 0);
	else if (*(r->fmt + 1) == 'u')
		sum += shorter_u_i(r, 10, 0);
	else if (*(r->fmt + 1) == 'x')
		sum += shorter_u_i(r, 16, 0);
	else if (*(r->fmt + 1) == 'i' || *(r->fmt + 1) == 'd')
		sum += shorter_i(r, 10, 0);
	else if (*(r->fmt + 1) == 'f')
		sum += shorter_f(r, 0);
	else
		sum += shorter_u_i_high(r, 16, 0);
	r->fmt++;
	return (sum);
}
