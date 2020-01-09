/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_datafile2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 23:27:01 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/08 09:26:51 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int						get_textures(t_data *data, t_texture_valid *validtxt)
{
	t_l t;

	init_validt(validtxt);
	t.fd = open("file.cub", O_RDONLY);
	while (get_next_line(t.fd, &t.line) > 0)
	{
		t.ptr = t.line;
		if (!ft_strncmp(t.line, "NO", 2))
			check_textures_ns(data, validtxt, t.ptr, 0);
		else if (!ft_strncmp(t.line, "SO", 2))
			check_textures_ns(data, validtxt, t.ptr, 1);
		else if (!ft_strncmp(t.line, "WE", 2))
			check_textures_ews(data, validtxt, t.ptr, 2);
		else if (!ft_strncmp(t.line, "EA", 2))
			check_textures_ews(data, validtxt, t.ptr, 3);
		else if (!ft_strncmp(t.line, "S ", 2))
			check_textures_ews(data, validtxt, t.ptr, 4);
		free(t.line);
	}
	free(t.line);
	if (validtxt->no && validtxt->so && validtxt->s &&
	validtxt->ea && validtxt->we)
		return (0);
	return (-1);
}

void					helpgetcolor(t_l *t, t_texture_valid *validtxt,
int *m, int *n)
{
	*n = 2;
	*m = 2;
	init_validt(validtxt);
	t->fd = open("file.cub", O_RDONLY);
}

int						get_color(t_data *data, t_texture_valid *validtxt)
{
	t_l t;
	int m;
	int n;

	helpgetcolor(&t, validtxt, &m, &n);
	while (get_next_line(t.fd, &t.line) > 0)
	{
		t.ptr = t.line;
		if (*t.line == 'F')
			m = check_color_f(data, validtxt, t.ptr);
		else if (*t.line == 'C')
			n = check_color_c(data, validtxt, t.ptr);
		free(t.line);
	}
	free(t.line);
	if (n == 0 || m == 0)
		return (0);
	if (validtxt->f == 1 && validtxt->c == 1)
		return (1);
	else
		return (-1);
	return (1);
}

int						get_positionplayer(t_data *data, t_wh_map *wh_map)
{
	t_l t;

	init_wh_map(wh_map);
	wh_map->i = 1;
	while (wh_map->i < data->map_height - 1)
	{
		wh_map->j = 1;
		while (wh_map->j < data->map_width - 1)
		{
			if ((t.ptr = ft_strchr("NSEW", data->map[wh_map->i][wh_map->j])))
			{
				init_angl_and_pos(data, wh_map->i, wh_map->j, wh_map);
				wh_map->k++;
			}
			wh_map->j++;
		}
		wh_map->i++;
	}
	if (!wh_map->k || wh_map->k > 1)
		return (ft_erreur_orien());
	return (0);
}

void					exceedspacecommon(char *ptr)
{
	while (*ptr == ' ' || *ptr == ',')
		ptr++;
}
