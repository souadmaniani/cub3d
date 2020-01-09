/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:43:51 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/07 09:15:44 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			move_player(void *param)
{
	t_data *data;

	data = (t_data*)param;
	mlx_destroy_image(data->mlx_ptr, g_img);
	mlx_clear_window(data->mlx_ptr, data->mlx_win);
	g_img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	ft_rendering(data);
	mlx_hook(data->mlx_win, 2, 0, key_hook, data);
	mlx_hook(data->mlx_win, 3, 1, release_hook, data);
	mlx_hook(data->mlx_win, 17, 0, expose, data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, g_img, 0, 0);
	return (0);
}

int			ft_loop(t_data *data)
{
	ft_rendering(data);
	if (g_save)
	{
		g_save = 0;
		return (create_bmp(data));
	}
	mlx_loop_hook(data->mlx_ptr, move_player, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

int			ft_cub3d(void)
{
	t_data		data;
	t_m			m;

	if (ft_window(&data) == -1)
		return (-1);
	if (!(m.t = mlx_xpm_file_to_image(data.mlx_ptr, data.texture1, &m.w, &m.h)))
		return (erreur_path());
	g_north_texture = (int*)mlx_get_data_addr(m.t, &m.n, &m.sln, &m.n);
	if (!(m.t = mlx_xpm_file_to_image(data.mlx_ptr, data.texture2, &m.w, &m.h)))
		return (erreur_path());
	g_south_texture = (int*)mlx_get_data_addr(m.t, &m.n, &m.sln, &m.h);
	if (!(m.t = mlx_xpm_file_to_image(data.mlx_ptr, data.texture3, &m.w, &m.h)))
		return (erreur_path());
	g_west_texture = (int*)mlx_get_data_addr(m.t, &m.n, &m.sln, &m.h);
	if (!(m.t = mlx_xpm_file_to_image(data.mlx_ptr, data.texture4, &m.w, &m.h)))
		return (erreur_path());
	g_east_texture = (int*)mlx_get_data_addr(m.t, &m.n, &m.sln, &m.h);
	if (!(m.t = mlx_xpm_file_to_image(data.mlx_ptr, data.stexture, &m.w, &m.h)))
		return (erreur_path());
	g_sprite_texture = (int*)mlx_get_data_addr(m.t, &m.n, &m.sln, &m.h);
	data.direction = init_point(data.pos_player.x + cos(data.ang_rotation) * 30,
	data.pos_player.y + sin(data.ang_rotation) * 30);
	if (ft_loop(&data) == 1)
		return (0);
	return (0);
}

int			ft_window(t_data *data)
{
	if (data_init(data) == -1)
	{
		ft_erreur_plus();
		return (-1);
	}
	if (!(data->mlx_ptr = mlx_init()))
		return (-1);
	if (!(data->mlx_win = mlx_new_window(data->mlx_ptr, data->win_width,
					data->win_height, "Wolf3d")))
		return (-1);
	g_img = mlx_new_image(data->mlx_ptr, data->win_width, data->win_height);
	return (0);
}

int			main(int argc, char *argv[])
{
	if (argc < 2)
		return (erreur_arg(0));
	else if (argc == 2 || argc == 3)
	{
		if (argc == 2 && ft_strncmp(".cub", ft_split(argv[1]), 4))
			return (erreur_arg(1));
		if (argc == 3 && ft_strncmp("--save", argv[2], 6))
		{
			write(1, "Error :not a good argument\n", 27);
			return (0);
		}
		if (argc == 3 && ft_strncmp("--save", argv[2], 6) == 0)
			g_save = 1;
		if (ft_cub3d() == -1)
			return (0);
	}
	else
	{
		write(1, "Error :more arguments\n", 22);
		return (0);
	}
	return (0);
}
