/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_erreur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 23:59:23 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/08 02:20:46 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_isprint(int c)
{
	if (c == 32 || (c > 8 && c < 12) || c == 13)
		return (1);
	return (0);
}

int			ft_detect_car(char *ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		if (ft_isprint(ptr[i]))
			i++;
		else
			return (0);
	}
	return (2);
}

int			erreur_path(void)
{
	write(1, "Error : invalid path\n", 21);
	return (-1);
}
