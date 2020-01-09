/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_configuration.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:16:05 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/08 09:26:31 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			check_valid_map(t_data *data, t_wh_map *wh_map)
{
	char **map;

	init_wh_map(wh_map);
	map = data->map;
	while (wh_map->i < data->map_height)
	{
		if (wh_map->i == 0 || wh_map->i == data->map_height - 1)
		{
			wh_map->j = 0;
			while (map[wh_map->i][wh_map->j])
			{
				if (map[wh_map->i][wh_map->j] != '1')
					return (-1);
				wh_map->j++;
			}
		}
		else if (map[wh_map->i][0] == '0' ||
		map[wh_map->i][data->map_width - 1] == '0')
			return (-1);
		wh_map->i++;
	}
	return (1);
}

void		check_textures_ns(t_data *data, t_texture_valid *validtxt,
char *ptr, int cas)
{
	if (cas == 0)
	{
		validtxt->no++;
		while (*ptr != '.')
			ptr++;
		data->texture1 = ft_strdup(ptr);
	}
	else if (cas == 1)
	{
		validtxt->so++;
		while (*ptr != '.')
			ptr++;
		data->texture2 = ft_strdup(ptr);
	}
}

void		check_textures_ews(t_data *data, t_texture_valid *validtxt,
char *ptr, int cas)
{
	if (cas == 2)
	{
		validtxt->we++;
		while (*ptr != '.')
			ptr++;
		data->texture3 = ft_strdup(ptr);
	}
	else if (cas == 3)
	{
		validtxt->ea++;
		while (*ptr != '.')
			ptr++;
		data->texture4 = ft_strdup(ptr);
	}
	else if (cas == 4)
	{
		validtxt->s++;
		while (*ptr != '.')
			ptr++;
		data->stexture = ft_strdup(ptr);
	}
}

int			check_color_f(t_data *data, t_texture_valid *validtxt,
char *ptr)
{
	int		i;
	char	*itodata;
	char	*line;

	i = 3;
	line = ptr;
	ptr++;
	exceedspace(&ptr);
	while (--i >= 0)
	{
		if (ft_atoi(ptr) < 0 || ft_atoi(ptr) > 255)
			ft_exit(&line);
		data->color_floor += ft_atoi(ptr) * pow(256, i);
		itodata = ft_itoa(ft_atoi(ptr));
		ptr = ptr + ft_strlen(itodata) + 1;
		free(itodata);
		if (i)
			exceedspacecommon(ptr);
	}
	validtxt->f++;
	ptr--;
	if (ptr && *ptr)
		return (ft_helpcolor(line, ptr));
	return (2);
}

int			check_color_c(t_data *data, t_texture_valid *validtxt,
char *ptr)
{
	int		i;
	char	*itodata;
	char	*line;

	i = 3;
	line = ptr;
	ptr++;
	exceedspace(&ptr);
	while (--i >= 0)
	{
		if (ft_atoi(ptr) < 0 || ft_atoi(ptr) > 255)
			ft_exit(&line);
		data->color_celling += ft_atoi(ptr) * pow(256, i);
		itodata = ft_itoa(ft_atoi(ptr));
		ptr = ptr + ft_strlen(itodata) + 1;
		free(itodata);
		if (i)
			exceedspacecommon(ptr);
	}
	validtxt->c++;
	ptr--;
	if (ptr && *ptr)
		return (ft_helpcolor(line, ptr));
	return (2);
}
