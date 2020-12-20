/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_of_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/20 20:54:36 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/20 20:54:47 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			length_of_num(unsigned long long int i, int base)
{
	int		length;

	length = 0;
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		length++;
	}
	while (i > 0)
	{
		i /= base;
		length++;
	}
	return (length);
}

int			length_of_num_i(long long int i, int base)
{
	int		length;

	length = 0;
	if (i < -9223372036854775807)
		return (20);
	if (i == 0)
		return (1);
	if (i < 0)
	{
		i *= -1;
		length++;
	}
	while (i > 0)
	{
		i /= base;
		length++;
	}
	return (length);
}
