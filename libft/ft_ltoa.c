/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:06:48 by ggeri             #+#    #+#             */
/*   Updated: 2020/09/16 15:53:06 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_fillmynbr(char *s, long long nb, int size)
{
	if (nb < 0)
	{
		s[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		size--;
		s[size] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (s);
}

char		*ft_ltoa(int length, t_arg *r)
{
	char	*temp;
	int		i;
	int		c;

	i = length_of_num_i(r->head, 10);
	temp = (void*)0;
	r->fstr = (char*)malloc(sizeof(char) * length);
	r->fstr[length - 1] = '\0';
	temp = r->fstr;
	ft_fillmynbr(temp, r->head, i);
	temp[i] = '.';
	temp = temp + i + 1;
	if (r->tail != 0)
		ft_fillmynbr(temp, r->tail, length_of_num_i(r->tail, 10));
	else
	{
		c = 0;
		while (c < length - i - 2)
			temp[c++] = 0 + '0';
	}
	return (r->fstr);
}
