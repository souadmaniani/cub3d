/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 00:19:33 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/06 19:54:31 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char			*buf(int n)
{
	int			i;
	char		*str;
	long		m;

	i = 0;
	m = n;
	while (m)
	{
		m = m / 10;
		i++;
	}
	if (n <= 0)
	{
		str = (char*)malloc(i + 2);
		if (!str)
			return (NULL);
		if (n == 0)
			str[0] = '0';
		if (n)
			str[0] = '-';
	}
	else
		str = (char*)malloc(i + 1);
	return (str);
}

char			*ft_itoa(int n)
{
	int			i;
	char		*str;
	long		m;

	m = n;
	str = NULL;
	i = 0;
	while (m)
	{
		m = m / 10;
		i++;
	}
	m = n;
	str = buf(n);
	if (!str)
		return (NULL);
	((n > 0) ? (i--) : (m = -m));
	str[i + 1] = '\0';
	while (m)
	{
		str[i--] = m % 10 + 48;
		m = m / 10;
	}
	return (str);
}
