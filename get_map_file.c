/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 23:39:25 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/05 14:48:15 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				allocation_map(t_data *data)
{
	t_wh_map wh_map;

	if (get_wh_map(data, &wh_map) == -1)
		return (-1);
	data->map = (char**)malloc(sizeof(char*) * data->map_height);
	return (2);
}

int				ft_check_map(char **line, int cas)
{
	if (cas == 0)
	{
		free(*line);
		return (0);
	}
	else if (cas == 1)
	{
		free(*line);
		return (1);
	}
	else if (cas == 2)
	{
		free(*line);
		return (-1);
	}
	return (2);
}

int				ft_search_number(t_data *data, int *i, int *j, t_l *t)
{
	data->map[*j] = (char*)malloc(sizeof(char) * (data->map_width + 1));
	*i = -1;
	while (*t->ptr && ++(*i) >= 0)
	{
		data->map[*j][*i] = *t->ptr++;
		while (!(ft_strchr("120NSEW", *t->ptr)) && *t->ptr)
		{
			if (ft_isprint(*t->ptr) == 1)
				t->ptr++;
			else
				return (ft_check_map(&t->line, 2));
		}
	}
	data->map[*j][++(*i)] = '\0';
	(*j)++;
	return (1);
}

int				ft_map(t_data *data, int i, int j, int k)
{
	t_l t;

	if (allocation_map(data) == -1)
		return (-1);
	t.fd = open("file.cub", O_RDONLY);
	while (((k = get_next_line(t.fd, &t.line)) >= 0))
	{
		t.ptr = t.line;
		if (j >= data->map_height)
		{
			j++;
			if ((ft_detect_car(t.ptr) == 0))
				return (ft_check_map(&t.line, 0));
			if (k == 0)
				return (ft_check_map(&t.line, 1));
		}
		if (*t.line == '1' && j < data->map_height)
		{
			if (ft_search_number(data, &i, &j, &t) == -1)
				return (-1);
		}
		free(t.line);
	}
	close(t.fd);
	return (1);
}
