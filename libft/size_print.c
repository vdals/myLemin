/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 16:24:12 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:51:35 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_print_hash(t_arg *r)
{
	int		sum;

	sum = 0;
	if (*(r->fmt + 1) == 'o' && r->hsh == 1)
		sum = ft_putchar('0');
	else if (*(r->fmt + 1) == 'x' && r->hsh == 1 && r->ull != 0)
		sum = ft_putstr("0x");
	else if (*(r->fmt + 1) == 'X' && r->hsh == 1 && r->ull != 0)
		sum = ft_putstr("0X");
	return (sum);
}

int			check_hash_help(t_arg *r)
{
	if (r->hsh == 1 && (*(r->fmt + 1) == 'x') && r->wiedth == 0 && r->zero == 0)
		return (0);
	if (r->hsh == 1 && (*(r->fmt + 1) == 'X') && r->wiedth == 0 && r->zero == 0)
		return (0);
	if (r->hsh == 1 && (*(r->fmt + 1) == 'o'))
		return (-1);
	else if (r->hsh == 1 && (*(r->fmt + 1) == 'x') && r->zero != 1)
		return (-2);
	else if (r->hsh == 1 && (*(r->fmt + 1) == 'X') && r->zero != 1)
		return (-2);
	else
		return (0);
}

int			ft_size_print(t_arg *r, int length)
{
	int		ret;

	r->counter = r->num - length + check_hash_help(r);
	ret = r->counter;
	if ((r->zero == 1) && (r->counter > 0))
	{
		while (r->counter--)
			ft_putchar('0');
	}
	else if ((r->zero != 1) && (r->counter > 0))
	{
		while (r->counter--)
			ft_putchar(' ');
	}
	if (ret < 0)
		return (0);
	else
		return (ret);
}

int			ft_size_print2(t_arg *r, int length)
{
	int		ret;

	r->counter = r->num - length + check_hash_help(r);
	ret = r->counter;
	if ((r->zero == 1) && (r->counter > 0))
	{
		ft_putstr("0x");
		while (r->counter--)
			ft_putchar('0');
	}
	else if ((r->zero != 1) && (r->counter > 0))
	{
		while (r->counter--)
			ft_putchar(' ');
		ft_putstr("0x");
	}
	if (ret < 0 && r->p != 0)
	{
		ft_putstr("0x");
		return (0);
	}
	else if (ret < 0)
		return (0);
	return (ret);
}

int			ft_size_print_minus(t_arg *r, int length)
{
	int		ret;

	r->counter = r->num - length;
	ret = r->counter;
	if (r->counter > 0)
	{
		while (r->counter--)
			ft_putchar(' ');
	}
	if (ret < 0)
		return (0);
	else
		return (ret);
}
