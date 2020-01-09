/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 10:31:51 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/06 19:46:15 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_atoi(const char *str)
{
	long	integer;
	int		i;
	int		sign;

	integer = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		integer = integer * 10 + str[i] - '0';
		if (integer > 4294967296 && sign == 1)
			return (-1);
		if (integer > 4294967296 && sign == -1)
			return (0);
		i++;
	}
	return (integer * sign);
}
