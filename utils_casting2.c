/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_casting2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:39:05 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/07 22:53:07 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_datasturct(t_data *data)
{
	data->color_floor = 0;
	data->map_width = 0;
	data->color_celling = 0;
	data->wall_height = 80;
	data->turndirection = 0;
	data->walkdirection = 0;
	data->movespeed = 41.0;
	data->rotationspeed = 15 * M_PI / 180;
}

void			ft_rayinit(t_data *data, t_ray *ray)
{
	init_ray(ray);
	g_tabl_rays = malloc(sizeof(t_ray) * data->win_width);
	ray->ray_angl = data->ang_rotation - FOFV / 2;
}
