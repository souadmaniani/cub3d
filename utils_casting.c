/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_casting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 11:45:44 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/05 18:02:22 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_intersh(t_data *data, t_ray *ray, t_point *wallhith,
t_intersh *intersh)
{
	ray->foundh = 0;
	wallhith->x = 0;
	wallhith->y = 0;
	intersh->yintercept = floor(data->pos_player.y / data->wall_height) *
	data->wall_height;
	intersh->yintercept += (rayfacingdown(ray)) ? data->wall_height : 0;
	intersh->xintercept = data->pos_player.x +
	(intersh->yintercept - data->pos_player.y) / tan(ray->ray_angl);
	intersh->ystep = data->wall_height;
	intersh->ystep *= (rayfacingup(ray)) ? -1 : 1;
	intersh->xstep = data->wall_height / tan(ray->ray_angl);
	intersh->xstep *= (rayfacingleft(ray) && intersh->xstep > 0) ? -1 : 1;
	intersh->xstep *= (rayfacingreight(ray) && intersh->xstep < 0) ? -1 : 1;
	intersh->nexthortx = intersh->xintercept;
	intersh->nexthorty = intersh->yintercept;
	if (rayfacingup(ray))
		intersh->nexthorty--;
}

void	init_intersv(t_data *data, t_ray *ray, t_point *wallhitv,
t_intersv *intersv)
{
	ray->foundv = 0;
	wallhitv->x = 0;
	wallhitv->y = 0;
	intersv->xintercept = floor(data->pos_player.x / data->wall_height) *
	data->wall_height;
	intersv->xintercept += (rayfacingreight(ray)) ? data->wall_height : 0;
	intersv->yintercept = data->pos_player.y + (intersv->xintercept -
	data->pos_player.x) * tan(ray->ray_angl);
	intersv->xstep = data->wall_height;
	intersv->xstep *= (rayfacingleft(ray)) ? -1 : 1;
	intersv->ystep = data->wall_height * tan(ray->ray_angl);
	intersv->ystep *= (rayfacingup(ray) && intersv->ystep > 0) ? -1 : 1;
	intersv->ystep *= (rayfacingdown(ray) && intersv->ystep < 0) ? -1 : 1;
	intersv->nextvertx = intersv->xintercept;
	intersv->nextverty = intersv->yintercept;
	if (rayfacingleft(ray))
		intersv->nextvertx--;
}

void	affect_vp(t_ray *ray, t_point *wallhitv, t_intersv *intersv)
{
	ray->foundv = 1;
	if (rayfacingleft(ray))
		intersv->nextvertx++;
	wallhitv->x = intersv->nextvertx;
	wallhitv->y = intersv->nextverty;
}

void	affect_hps(t_data *data, t_ray *ray, t_point *hiths,
t_intersh *intersh)
{
	g_xsprite = ((int)(intersh->nexthortx / data->wall_height)) *
	data->wall_height + data->wall_height / 2;
	g_ysprite = ((int)((intersh->nexthorty) / data->wall_height)) *
	data->wall_height + data->wall_height / 2;
	ray->sprite.foundhs = 1;
	hiths->x = intersh->nexthortx;
	hiths->y = intersh->nexthorty;
}

void	affect_vps(t_data *data, t_ray *ray, t_point *hitvs,
t_intersv *intersv)
{
	g_xspritev = (int)(intersv->nextvertx / data->wall_height) *
	data->wall_height + data->wall_height / 2;
	g_yspritev = (int)(intersv->nextverty / data->wall_height) *
	data->wall_height + data->wall_height / 2;
	ray->sprite.foundvs = 1;
	hitvs->x = intersv->nextvertx;
	hitvs->y = intersv->nextverty;
}
