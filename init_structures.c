/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:11:08 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/07 22:52:33 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		init_wh_map(t_wh_map *wh_map)
{
	wh_map->i = 0;
	wh_map->j = 0;
	wh_map->k = 0;
}

void		init_angl_and_pos(t_data *data, int i, int j, t_wh_map *wh_map)
{
	data->pos_player.x = wh_map->j * data->wall_height +
	data->wall_height / 2;
	data->pos_player.y = wh_map->i * data->wall_height +
	data->wall_height / 2;
	if (data->map[i][j] == 'N')
		data->ang_rotation = 3 * M_PI / 2.0;
	else if (data->map[i][j] == 'S')
		data->ang_rotation = M_PI / 2.0;
	else if (data->map[i][j] == 'E')
		data->ang_rotation = M_PI;
	else if (data->map[i][j] == 'W')
		data->ang_rotation = 0;
}

void		init_validt(t_texture_valid *validtxt)
{
	validtxt->ea = 0;
	validtxt->no = 0;
	validtxt->s = 0;
	validtxt->so = 0;
	validtxt->we = 0;
	validtxt->f = 0;
	validtxt->c = 0;
}

void		ft_data_init(t_data *data, t_k *init)
{
	init->i = -1;
	init->k = 0;
	init->j = 0;
	init->m = 0;
	init_datasturct(data);
}

int			data_init(t_data *data)
{
	t_texture_valid	validtxt;
	t_wh_map		wh_map;
	t_k				init;

	ft_data_init(data, &init);
	init.m = get_resolution(data, &init.i);
	if (init.m == 0 || init.m == -1)
		return (-1);
	init.i = -1;
	init.m = get_color(data, &validtxt);
	if (init.m == -1 || init.m == 0)
		return (-1);
	init.m = ft_map(data, init.i, init.j, init.k);
	if (init.m == -1 || init.m == 0)
		return (-1);
	if (check_valid_map(data, &wh_map) == -1)
		return (ft_erreur_walls());
	if (get_textures(data, &validtxt) == -1)
		return (ft_erreur_key());
	if (get_positionplayer(data, &wh_map) == -1)
		return (-1);
	return (0);
}
