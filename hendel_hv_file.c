/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hendel_hv_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 08:17:38 by smaniani          #+#    #+#             */
/*   Updated: 2019/12/29 22:39:39 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	affect_hp(t_ray *ray, t_point *wallhith, t_intersh *intersh)
{
	ray->foundh = 1;
	if (rayfacingup(ray))
		intersh->nexthorty++;
	wallhith->x = intersh->nexthortx;
	wallhith->y = intersh->nexthorty;
}

void	ft_hendelhorizontalinters(t_data *data, t_ray *ray, t_point *wallhith)
{
	t_intersh	intersh;

	init_intersh(data, ray, wallhith, &intersh);
	while (1)
	{
		intersh.x = (int)((intersh.nexthorty) / data->wall_height);
		intersh.y = (int)(intersh.nexthortx / data->wall_height);
		if (intersh.x < data->map_height && intersh.y < data->map_width
		&& intersh.x >= 0 && intersh.y >= 0)
		{
			if (data->map[(int)((intersh.nexthorty) / data->wall_height)]
			[(int)((intersh.nexthortx) / data->wall_height)] == '1')
			{
				affect_hp(ray, wallhith, &intersh);
				break ;
			}
			else
			{
				intersh.nexthortx += intersh.xstep;
				intersh.nexthorty += intersh.ystep;
			}
		}
		else
			break ;
	}
}

void	ft_hendelverticalinters(t_data *data, t_ray *ray, t_point *wallhitv)
{
	t_intersv intersv;

	init_intersv(data, ray, wallhitv, &intersv);
	while (1)
	{
		intersv.x = (int)intersv.nextverty / data->wall_height;
		intersv.y = (int)intersv.nextvertx / data->wall_height;
		if (intersv.x < data->map_height && intersv.y < data->map_width
		&& intersv.x >= 0 && intersv.y >= 0)
		{
			if (data->map[(int)intersv.nextverty / data->wall_height]
			[(int)intersv.nextvertx / data->wall_height] == '1')
			{
				affect_vp(ray, wallhitv, &intersv);
				break ;
			}
			else
			{
				intersv.nextvertx += intersv.xstep;
				intersv.nextverty += intersv.ystep;
			}
		}
		else
			break ;
	}
}

void	ft_hendelhorizontalinterssprite(t_data *data, t_ray *ray,
t_point *hiths)
{
	t_intersh intersh;

	init_intersh(data, ray, hiths, &intersh);
	while (1)
	{
		intersh.x = (int)((intersh.nexthorty) / data->wall_height);
		intersh.y = (int)(intersh.nexthortx / data->wall_height);
		if (intersh.x < data->map_height && intersh.y < data->map_width &&
		intersh.x >= 0 && intersh.y >= 0)
		{
			if (data->map[(int)((intersh.nexthorty) / data->wall_height)]
			[(int)(intersh.nexthortx / data->wall_height)] == '2')
			{
				affect_hps(data, ray, hiths, &intersh);
				break ;
			}
			else
			{
				intersh.nexthortx += intersh.xstep;
				intersh.nexthorty += intersh.ystep;
			}
		}
		else
			break ;
	}
}

void	ft_hendelverticalinterssprite(t_data *data, t_ray *ray, t_point *hitvs)
{
	t_intersv intersv;

	init_intersv(data, ray, hitvs, &intersv);
	while (1)
	{
		intersv.x = (int)intersv.nextverty / data->wall_height;
		intersv.y = (int)intersv.nextvertx / data->wall_height;
		if (intersv.x < data->map_height && intersv.y < data->map_width &&
		intersv.x >= 0 && intersv.y >= 0)
		{
			if (data->map[(int)intersv.nextverty / data->wall_height]
			[(int)intersv.nextvertx / data->wall_height] == '2')
			{
				affect_vps(data, ray, hitvs, &intersv);
				break ;
			}
			else
			{
				intersv.nextvertx += intersv.xstep;
				intersv.nextverty += intersv.ystep;
			}
		}
		else
			break ;
	}
}
