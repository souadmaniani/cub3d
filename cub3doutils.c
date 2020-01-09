/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3doutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 20:21:58 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/08 00:24:50 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		ft_rendering(t_data *data)
{
	ft_renderprojectionwall(data);
	ft_renderprojectionsprite(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, g_img, 0, 0);
}

char		*ft_split(char *str)
{
	while (*str != '.')
		str++;
	return (str);
}

int			release_hook(int key, t_data *data)
{
	if (key == 12 || key == 126)
		data->walkdirection = 0;
	else if (key == 6 || key == 125)
		data->walkdirection = 0;
	else if (key == 123 || key == 1)
		data->turndirection = 0;
	else if (key == 124 || key == 2)
		data->turndirection = 0;
	return (key);
}

void		ft_wh_map(t_wh_map *wh_map, t_l *t, int *m)
{
	wh_map->i = 0;
	t->ptr = t->line;
	while (*t->ptr != '\0')
	{
		if (ft_strchr("102NSEW", *t->ptr))
			wh_map->i++;
		t->ptr++;
	}
	wh_map->k++;
	*m = (wh_map->k == 1) ? wh_map->i : *m;
	wh_map->j++;
}
