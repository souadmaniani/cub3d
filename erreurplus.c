/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreurplus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 09:03:06 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/08 09:27:57 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			ft_freetabledoubl(char **tabl)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tabl[i] != NULL)
		i++;
	while (i >= 0)
	{
		i--;
		free(tabl[j]);
		j++;
	}
	free(tabl);
	tabl = NULL;
	return (0);
}

int			erreur_arg(int cas)
{
	if (cas == 0)
	{
		write(1, "Error :argument not found\n", 27);
		return (0);
	}
	if (cas == 1)
	{
		write(1, "Error :file don't have extention .cub\n", 38);
		return (0);
	}
	return (0);
}

void		my_freeexit(char *line, char **datasplitted)
{
	ft_freetabledoubl(datasplitted);
	ft_exit(&line);
}

void		helpheckother(char *line, char **datasplitted)
{
	if (ft_strlen(datasplitted[0]) == 1)
	{
		if (ft_strncmp(datasplitted[0], "F", 1) != 0 &&
			ft_strncmp(datasplitted[0], "S", 1) != 0 &&
			ft_strncmp(datasplitted[0], "C", 1) != 0 &&
			ft_strncmp(datasplitted[0], "R", 1) != 0 &&
			ft_strncmp(datasplitted[0], "1", 1) != 0)
			my_freeexit(line, datasplitted);
	}
	else if (ft_strlen(datasplitted[0]) == 2)
	{
		if (ft_strncmp(datasplitted[0], "NO", 2) != 0 &&
			ft_strncmp(datasplitted[0], "SO", 2) != 0 &&
			ft_strncmp(datasplitted[0], "WE", 2) != 0 &&
			ft_strncmp(datasplitted[0], "EA", 2) != 0)
			my_freeexit(line, datasplitted);
	}
	else if (datasplitted[0][0] != '1' && ft_strlen(datasplitted[0]) > 2)
		my_freeexit(line, datasplitted);
}

void		checkotherspar(t_data *data, char **line)
{
	char	**datasplitted;

	datasplitted = ft_split1(*line, ' ');
	if (datasplitted[0] != NULL)
	{
		helpheckother(*line, datasplitted);
		ft_freetabledoubl(datasplitted);
	}
	if (**line == '\0')
		ft_freetabledoubl(datasplitted);
	if (data->map_width != 0 && **line == '\0')
	{
		write(1, "Error : File not valid\n", 24);
		free(*line);
		*line = NULL;
		exit(0);
	}
}
