/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnco.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 14:34:01 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/14 15:10:39 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_hash(t_arg *r)
{
	while (*(r->fmt + 1) == '#')
	{
		r->hsh = 1;
		r->fmt++;
	}
	return (r->hsh);
}

int		ft_check_zero(t_arg *r)
{
	while (*(r->fmt + 1) == '0')
	{
		r->fmt++;
		r->zero = 1;
	}
	return (r->zero);
}

int		ft_check_num(t_arg *r)
{
	int	num;

	num = 0;
	if ((*(r->fmt + 1) >= '0') && (*(r->fmt + 1) <= '9'))
	{
		num = ft_atoi(r->fmt + 1);
		r->fmt = r->fmt + length_of_num(num, 10);
		return (num);
	}
	else
		return (0);
}

int		ft_check_space(t_arg *r)
{
	if (*(r->fmt + 1) == ' ')
	{
		while (*(r->fmt + 1) == ' ')
			r->fmt++;
		return (1);
	}
	else
		return (0);
}

int		ft_check_plus(t_arg *r)
{
	while (*(r->fmt + 1) == '+')
	{
		r->fmt++;
		r->plus = 1;
	}
	return (r->plus);
}
