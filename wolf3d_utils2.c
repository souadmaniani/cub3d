/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:48:02 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/07 00:31:43 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

float			ft_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(pow(x2 - x1, 2) + (pow(y2 - y1, 2))));
}

int				put_color_in_image(int x, int y, int color,
t_data *data)
{
	int			no;
	int			d;
	int			size_line;
	int			*img_set;

	img_set = (int*)mlx_get_data_addr(g_img, &no, &size_line, &d);
	if (y < data->win_height && x < data->win_width && y >= 0 && x >= 0)
		img_set[y * (size_line / 4) + x] = color;
	else
		return (-1);
	return (0);
}

int				key_pressed(int key, t_data *data)
{
	if (key == 12 || key == 6 || key == 124 || key == 123 || key == 53 ||
	key == 1 || key == 2 || key == 126 || key == 125)
	{
		if (key == 12 || key == 126)
			data->walkdirection = 1;
		else if (key == 6 || key == 125)
			data->walkdirection = -1;
		else if (key == 123 || key == 1)
			data->turndirection = -1;
		else if (key == 124 || key == 2)
			data->turndirection = +1;
		else if (key == 53)
			exit(1);
		return (1);
	}
	else
		return (0);
}

int				expose(void *param)
{
	t_data	*data;

	data = (t_data*)param;
	mlx_destroy_image(data->mlx_ptr, g_img);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	exit(1);
	return (0);
}

int				key_hook(int key, void *param)
{
	t_data					*data;
	t_point					p1;
	int						x1;
	int						y1;

	data = (t_data*)param;
	if (key_pressed(key, data))
	{
		data->ang_rotation += data->turndirection * data->rotationspeed;
		data->movestep = data->walkdirection * data->movespeed;
		p1.x = data->pos_player.x + cos(data->ang_rotation) * data->movestep;
		p1.y = data->pos_player.y + sin(data->ang_rotation) * data->movestep;
		x1 = p1.x / data->wall_height;
		y1 = p1.y / data->wall_height;
		if (!(data->map[y1][x1] == '1' || data->map[y1][x1] == '2'))
			data->pos_player = init_point(p1.x, p1.y);
		data->direction = init_point(data->pos_player.x +
		cos(data->ang_rotation) * 30, data->pos_player.y +
		sin(data->ang_rotation) * 30);
		if (key == 12 || key == 126 || key == 6 || key == 125)
			data->walkdirection = 0;
		else if (key == 123 || key == 1 || key == 124 || key == 2)
			data->turndirection = 0;
	}
	return (0);
}
