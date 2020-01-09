/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 23:13:54 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/05 16:33:57 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_point		init_point(float x, float y)
{
	static t_point point;

	point.x = x;
	point.y = y;
	return (point);
}

int			ft_erreur_key(void)
{
	write(1, "Error : Key not found or set twice \n", 37);
	return (-1);
}

int			ft_erreur_orien(void)
{
	write(1, "Error : orientation not found\n", 31);
	return (-1);
}

int			ft_erreur_walls(void)
{
	write(1, "Error : map not closed by Walls\n", 33);
	return (-1);
}

int			ft_erreur_plus(void)
{
	write(1, "Error : File not valid\n", 24);
	return (0);
}
