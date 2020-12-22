/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnydia <jnydia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:13:46 by ggeri             #+#    #+#             */
/*   Updated: 2020/12/22 17:47:15 by jnydia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int					neg;
	unsigned long long	res;

	res = 0;
	neg = 1;
	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\r' ||\
			*str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		if ((res >= 9223372036854775807 && neg == 1) || res > INT_MAX)
			return (-1);
		if (res > 9223372036854775807 && neg == -1)
			return (0);
		str++;
	}
	return (res * neg);
}
