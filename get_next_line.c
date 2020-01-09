/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:54:41 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/07 00:42:34 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int g_buffer_size = 1;

char						*resize(char *line)
{
	int						i;
	char					*tmp;
	char					*ptr;

	i = 0;
	ptr = line;
	while (line[i] != '\n' && line[i])
		i++;
	if (!(tmp = calloc(i + 1, 1)))
		return (0);
	line[i] = '\0';
	ft_strcpy(tmp, line);
	free(ptr);
	ptr = NULL;
	if (!(line = calloc(i + 1, 1)))
		return (0);
	ft_strcpy(line, tmp);
	free(tmp);
	tmp = NULL;
	return (line);
}

int							free_table(char **table, char **ptr)
{
	free(*table);
	*table = NULL;
	free(*ptr);
	*ptr = NULL;
	return (-1);
}

int							fill_line(char **stock, char **line, int cas)
{
	char					*tmp;

	if (cas == 1)
	{
		if (*stock)
		{
			tmp = *line;
			if (!(*line = ft_strjoin(*stock, *line)))
				return (-1);
			free_table(stock, &tmp);
		}
	}
	if (cas == 2)
	{
		tmp = *stock;
		if (!(*stock = ft_strjoin(*stock, *line)))
			return (-1);
		free_table(&tmp, line);
	}
	return (1);
}

int							get_next_line(int fd, char **line)
{
	static char				*stock = NULL;
	int						n;
	char					*ptr;
	char					*tmp;

	if (!g_buffer_size || !(*line = ft_calloc(1, 1)))
		return (-1);
	n = (fill_line(&stock, line, 1) == -1) ? -1 : 1;
	while (!(tmp = ft_strchr(*line, '\n')))
	{
		if ((!(ptr = ft_calloc(g_buffer_size + 1, 1))) || n == -1)
			return (-1);
		if (((n = read(fd, ptr, g_buffer_size)) == 0))
		{
			free(ptr);
			return (0);
		}
		if (n == -1)
			return (free_table(line, &ptr));
		n = (n && fill_line(line, &ptr, 2) == -1) ? -1 : n;
	}
	if (!(stock = ft_calloc(ft_strlen(tmp + 1) + 1, 1)))
		return (-1);
	ft_strcpy(stock, tmp + 1);
	return (!(*line = resize(*line))) ? -1 : 1;
}
