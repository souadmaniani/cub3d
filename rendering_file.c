/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 09:40:28 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/07 21:15:23 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	ft_help_renderw(t_data *data, t_rend *rd)
{
	rd->fcr = (float)T_HEIGHT / rd->pwallheigh;
	rd->offy = (rd->j + (-data->win_height / 2) +
	(rd->pwallheigh / 2)) * rd->fcr;
	if (g_tabl_rays[rd->i].foundv)
	{
		if (rayfacingreight(&g_tabl_rays[rd->i]) && rd->offx < T_WIDTH &&
		rd->offy >= 0 && rd->offy < T_HEIGHT)
			rd->color = g_west_texture[((T_WIDTH * rd->offy) + rd->offx)];
		else if (rayfacingleft(&g_tabl_rays[rd->i]) && rd->offx >= 0 &&
		rd->offx < T_WIDTH && rd->offy >= 0 && rd->offy < T_HEIGHT)
			rd->color = g_east_texture[((T_WIDTH * rd->offy) + rd->offx)];
	}
	else
	{
		if (rayfacingdown(&g_tabl_rays[rd->i]) && rd->offx >= 0 &&
		rd->offx < T_WIDTH && rd->offy >= 0 && rd->offy < T_HEIGHT)
			rd->color = g_south_texture[((T_WIDTH * rd->offy) + rd->offx)];
		else if (rayfacingup(&g_tabl_rays[rd->i]) && rd->offx >= 0 &&
		rd->offx < T_WIDTH && rd->offy >= 0 && rd->offy < T_HEIGHT)
			rd->color = g_north_texture[((T_WIDTH * rd->offy) + rd->offx)];
	}
	put_color_in_image(rd->i, rd->j, rd->color, data);
	rd->j++;
}

void	ft_help_renderw2(t_data *data, t_rend *rd)
{
	g_tabl_rays[rd->i].distance = cos(data->ang_rotation -
	g_tabl_rays[rd->i].ray_angl) * g_tabl_rays[rd->i].distance;
	rd->pwallheigh = data->wall_height * rd->distfpp /
	g_tabl_rays[rd->i].distance;
	rd->j = 0;
	rd->walltoppxl = (data->win_height / 2) - (rd->pwallheigh / 2);
	rd->walltoppxl = (rd->walltoppxl < 0) ? 0 : rd->walltoppxl;
	while (rd->j < rd->walltoppxl)
	{
		put_color_in_image(rd->i, rd->j, data->color_celling, data);
		rd->j++;
	}
	rd->j = rd->walltoppxl;
	rd->wallbpixl = (data->win_height / 2) + (rd->pwallheigh / 2);
	rd->wallbpixl = (rd->wallbpixl < 0) ? 0 : rd->wallbpixl;
}

void	ft_renderprojectionwall(t_data *data)
{
	t_rend rd;

	ft_castrayswalls(data);
	rd.distfpp = (data->win_width / 2) / tan(FOFV / 2);
	rd.i = -1;
	while (++rd.i < data->win_width)
	{
		ft_help_renderw2(data, &rd);
		if (g_tabl_rays[rd.i].foundv)
			rd.offx = (int)g_tabl_rays[rd.i].wallhity % data->wall_height;
		else
			rd.offx = (int)g_tabl_rays[rd.i].wallhitx % data->wall_height;
		while (rd.j < rd.wallbpixl)
			ft_help_renderw(data, &rd);
		rd.wallbpixl = (data->win_height / 2) + (rd.pwallheigh / 2);
		rd.j = rd.wallbpixl;
		while (rd.j < data->win_height)
		{
			put_color_in_image(rd.i, rd.j, data->color_floor, data);
			rd.j++;
		}
	}
}

void	ft_help_renders(t_data *data, t_rend *rd)
{
	rd->offx = g_tabl_rays_sprite[rd->i].sprite.raydists;
	rd->walltoppxl = (data->win_height / 2) - (rd->pspriteheigh / 2);
	rd->walltoppxl = (rd->walltoppxl < 0) ? 0 : rd->walltoppxl;
	rd->wallbpixl = (data->win_height / 2) + (rd->pspriteheigh / 2);
	rd->j = rd->walltoppxl;
	while (rd->j < rd->wallbpixl)
	{
		rd->fcr = (float)(T_HEIGHT / rd->pspriteheigh);
		rd->offy = (rd->j + (rd->pspriteheigh / 2) -
		(data->win_height / 2)) * rd->fcr;
		if (rd->offx >= 0 && rd->offx < T_WIDTH &&
		rd->offy >= 0 && rd->offy < T_HEIGHT)
		{
			rd->var = (rd->offy * T_WIDTH) + data->wall_height / 2
			- rd->offx;
			rd->var = (rd->var < 0) ? 0 : rd->var;
			rd->color = g_sprite_texture[rd->var];
		}
		if ((rd->color != 0 && g_tabl_rays[rd->i].distance >
		g_tabl_rays_sprite[rd->i].distance && g_tabl_rays_sprite[rd->i].
		sprite.wallhitxs && g_tabl_rays_sprite[rd->i].sprite.wallhitys))
			put_color_in_image(rd->i, rd->j, rd->color, data);
		rd->j++;
	}
}

void	ft_renderprojectionsprite(t_data *data)
{
	t_rend rd;

	ft_castrayssprite(data);
	rd.distfpp = (data->win_width / 2) / tan(FOFV / 2);
	rd.i = -1;
	while (++rd.i < data->win_width)
	{
		if (g_tabl_rays_sprite[rd.i].sprite.foundhs ||
		g_tabl_rays_sprite[rd.i].sprite.foundvs)
		{
			rd.pspriteheigh = data->wall_height *
			rd.distfpp / g_tabl_rays_sprite[rd.i].sprite.distfs;
		}
		if (g_tabl_rays_sprite[rd.i].sprite.foundhs ||
		g_tabl_rays_sprite[rd.i].sprite.foundvs)
			ft_help_renders(data, &rd);
	}
	free(g_tabl_rays_sprite);
	free(g_tabl_rays);
}
