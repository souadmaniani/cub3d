/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:36:28 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/09 11:23:08 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_resol(t_data *data, t_l *t)
{
	char	*itodata;

	data->win_height = ft_atoi(t->ptr);
	itodata = ft_itoa(data->win_height);
	t->ptr += ft_strlen(itodata);
	data->win_width = (data->win_width > MX) ? MX : data->win_width;
	data->win_height = (data->win_height > MY) ? MY : data->win_height;
	free(itodata);
	if (data->win_height < 0 || data->win_width < 0)
		return (-1);
	return (2);
}

int			get_reshelp(t_data *data, t_l *t, int *k)
{
	char *buf;

	buf = t->line;
	*k = 2;
	if (ft_resol(data, t) == -1)
	{
		free(buf);
		return (-1);
	}
	else if (t->ptr && *t->ptr)
	{
		*k = ft_detect_car(t->ptr);
		free(buf);
		return (*k);
	}
	else
	{
		free(buf);
		return (*k);
	}
}

int			get_resolution(t_data *data, int *i)
{
	t_l		t;
	int		k;
	char	*itodata;

	t.fd = open("file.cub", O_RDONLY);
	while (get_next_line(t.fd, &t.line) > 0)
	{
		if (*t.line == 'R')
		{
			*i = 7;
			t.ptr = t.line;
			t.ptr++;
			while (*t.ptr == ' ')
				t.ptr++;
			data->win_width = ft_atoi(t.ptr);
			itodata = ft_itoa(data->win_width);
			t.ptr = t.ptr + ft_strlen(itodata) + 1;
			free(itodata);
			while (*t.ptr == ' ')
				t.ptr++;
			return (get_reshelp(data, &t, &k));
		}
		free(t.line);
	}
	return (*i);
}

void		helpgetwhmap(t_wh_map *wh_map, t_l *t, int *a)
{
	init_wh_map(wh_map);
	t->fd = open("file.cub", O_RDONLY);
	*a = 1;
}

int			get_wh_map(t_data *data, t_wh_map *wh_map)
{
	t_l t;
	int m;
	int	a;

	helpgetwhmap(wh_map, &t, &a);
	while (a > 0)
	{
		a = get_next_line(t.fd, &t.line);
		if (*t.line == '1')
		{
			ft_wh_map(wh_map, &t, &m);
			if (wh_map->i != m)
			{
				free(t.line);
				return (-1);
			}
			data->map_width = wh_map->i;
		}
		else
			checkotherspar(data, &t.line);
		free(t.line);
	}
	data->map_height = (*t.line == 1) ? wh_map->j + 1 : wh_map->j;
	data->map_width = wh_map->i;
	return (2);
}
