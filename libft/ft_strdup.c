/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeri <ggeri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 21:39:33 by ggeri             #+#    #+#             */
/*   Updated: 2020/08/31 17:02:21 by ggeri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*temp;
	size_t	length;
	size_t	i;

	length = 0;
	while (src[length] != '\0')
		length++;
	temp = (char*)malloc(sizeof(char) * (length + 1));
	if (temp == (void*)0)
		return ((void*)0);
	i = 0;
	while (i < length)
	{
		temp[i] = src[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
