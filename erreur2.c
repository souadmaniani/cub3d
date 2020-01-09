/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erreur2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 07:58:19 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/08 09:23:13 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		ft_exit(char **line)
{
	if (*line)
	{
		free(*line);
		*line = NULL;
	}
	write(1, "Error : File not valid\n", 24);
	exit(0);
	return (0);
}

int		ft_helpcolor(char *line, char *ptr)
{
	int k;

	k = 0;
	k = ft_detect_car(ptr);
	free(line);
	return (k);
}

void	exceedspace(char **ptr)
{
	while (**ptr == ' ')
		(*ptr)++;
}
