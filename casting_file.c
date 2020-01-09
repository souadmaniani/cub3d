/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 14:51:40 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/05 17:01:37 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_ray(t_ray *ray)
{
	ray->column = -1;
	ray->wallhitx = 0;
	ray->wallhity = 0;
}

void			ft_castrayswalls(t_data *data)
{
	t_ray	ray;
	t_point wallhith;
	t_point wallhitv;
	float	hdistance;
	float	vdistance;

	ft_rayinit(data, &ray);
	normalize_angl(&ray);
	while (++ray.column < data->win_width)
	{
		ft_hendelverticalinters(data, &ray, &wallhitv);
		ft_hendelhorizontalinters(data, &ray, &wallhith);
		hdistance = (ray.foundh) ? ft_distance(data->pos_player.x,
		data->pos_player.y, wallhith.x, wallhith.y) : 2147483647.0;
		vdistance = (ray.foundv) ? ft_distance(data->pos_player.x,
		data->pos_player.y, wallhitv.x, wallhitv.y) : 2147483647.0;
		ray.wallhitx = (hdistance < vdistance) ? wallhith.x : wallhitv.x;
		ray.wallhity = (hdistance < vdistance) ? wallhith.y : wallhitv.y;
		ray.distance = (hdistance < vdistance) ? hdistance : vdistance;
		ray.foundh = (ray.foundh && hdistance < vdistance) ? 1 : 0;
		ray.foundv = (ray.foundv && !(hdistance < vdistance)) ? 1 : 0;
		g_tabl_rays[ray.column] = ray;
		ray.ray_angl += FOFV / data->win_width;
		normalize_angl(&ray);
	}
}

void			ft_rayinits(t_data *data, t_ray *ray)
{
	ray->column = -1;
	g_tabl_rays_sprite = malloc(sizeof(t_ray) * data->win_width);
	ray->ray_angl = data->ang_rotation - FOFV / 2;
	normalize_angl(ray);
}

void			ft_spriteinfo(t_data *data, t_ray *ray, t_point *hitsh,
t_point *hitsv)
{
	float			hdistances;
	float			vdistances;

	hdistances = (ray->sprite.foundhs) ? ft_distance(data->pos_player.x,
	data->pos_player.y, hitsh->x, hitsh->y) : 2147483647.0;
	vdistances = (ray->sprite.foundvs) ? ft_distance(data->pos_player.x,
	data->pos_player.y, hitsv->x, hitsv->y) : 2147483647.0;
	ray->sprite.foundhs = (ray->sprite.foundhs && hdistances < vdistances)
	? 1 : 0;
	ray->sprite.foundvs = (ray->sprite.foundvs && !(hdistances < vdistances)) ?
	1 : 0;
	ray->sprite.wallhitxs = (hdistances < vdistances) ? hitsh->x : hitsv->x;
	ray->sprite.wallhitys = (hdistances < vdistances) ? hitsh->y : hitsv->y;
	ray->distance = (hdistances < vdistances) ? hdistances : vdistances;
	ray->sprite.p0.x = (hdistances < vdistances) ? g_xsprite : g_xspritev;
	ray->sprite.p0.y = (hdistances < vdistances) ? g_ysprite : g_yspritev;
	if ((data->pos_player.x - ray->sprite.wallhitxs) && ray->sprite.wallhitxs)
	{
		ray->m = (data->pos_player.y - ray->sprite.wallhitys) /
		(data->pos_player.x - ray->sprite.wallhitxs);
		ray->ms = -1.0 / ray->m;
	}
}

void			ft_castrayssprite(t_data *data)
{
	t_ray	ray;
	t_point hitsh;
	t_point hitsv;

	ft_rayinits(data, &ray);
	while (++ray.column < data->win_width)
	{
		ft_hendelhorizontalinterssprite(data, &ray, &hitsh);
		ft_hendelverticalinterssprite(data, &ray, &hitsv);
		if (ray.sprite.foundhs || ray.sprite.foundvs)
		{
			ft_spriteinfo(data, &ray, &hitsh, &hitsv);
			ray.b1 = data->pos_player.y - ray.m * data->pos_player.x;
			ray.b2 = ray.sprite.p0.y - ray.ms * ray.sprite.p0.x;
			ray.sprite.intesrsp.x = (ray.b2 - ray.b1) / (ray.m - ray.ms);
			ray.sprite.intesrsp.y = ray.m * ray.sprite.intesrsp.x + ray.b1;
			ray.sprite.distfs = sqrt(pow((ray.sprite.p0.x - data->pos_player.x),
			2) + pow((ray.sprite.p0.y - data->pos_player.y), 2));
			ray.sprite.raydists = sqrt(pow((ray.sprite.intesrsp.x - ray.sprite.
			p0.x), 2) + pow((ray.sprite.intesrsp.y - ray.sprite.p0.y), 2));
		}
		g_tabl_rays_sprite[ray.column] = ray;
		ray.ray_angl += FOFV / data->win_width;
		normalize_angl(&ray);
	}
}
