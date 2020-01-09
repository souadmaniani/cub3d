/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmpfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 23:12:19 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/07 09:20:35 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_bmp_header(unsigned char *buff, t_bitmap *bmp, t_data *data)
{
	bmp->pd_offset = 54;
	bmp->header_size = 40;
	bmp->image_width = data->win_width;
	bmp->image_height = data->win_height;
	bmp->bpp = 24;
	bmp->width_in_bytes = ((bmp->image_width * bmp->bpp + 31) / 32) * 4;
	bmp->planes = 1;
	bmp->image_size = bmp->width_in_bytes * bmp->image_height;
	bmp->file_size = 54 + bmp->image_size;
	ft_memcpy(buff, "BM", 2);
	ft_memcpy(buff + 2, &(bmp->file_size), 4);
	ft_memcpy(buff + 10, &(bmp->pd_offset), 4);
	ft_memcpy(buff + 14, &(bmp->header_size), 4);
	ft_memcpy(buff + 18, &(bmp->image_width), 4);
	ft_memcpy(buff + 22, &(bmp->image_height), 4);
	ft_memcpy(buff + 26, &(bmp->planes), 2);
	ft_memcpy(buff + 28, &(bmp->bpp), 2);
	ft_memcpy(buff + 34, &(bmp->image_size), 4);
}

void		put_color_buff(unsigned char *buffer, t_bitmap *bmp, t_data *data)
{
	int		row;
	int		col;
	int		y2;
	int		tab_color[3];
	int		color;

	row = data->win_height;
	y2 = 0;
	while (--row >= 0)
	{
		col = data->win_width;
		while (--col >= 0)
		{
			color = get_color_off_image(col, row);
			decimal_to_rgb(color, tab_color, tab_color + 1, tab_color + 2);
			buffer[y2 * bmp->width_in_bytes + col * 3] = tab_color[0];
			buffer[y2 * bmp->width_in_bytes + col * 3 + 1] = tab_color[1];
			buffer[y2 * bmp->width_in_bytes + col * 3 + 2] = tab_color[2];
		}
		y2++;
	}
}

void		init_header(unsigned char *header)
{
	int		i;

	i = 55;
	while (--i >= 0)
		header[i] = 0;
}

int			create_bmp(t_data *data)
{
	t_bitmap		bmp;
	int				fd;
	unsigned char	header[54];
	unsigned char	*buffer;

	init_header(header);
	buffer = calloc(bmp.image_size, sizeof(unsigned char));
	fd = open("img.bmp", O_RDWR | O_CREAT, 777);
	set_bmp_header(header, &bmp, data);
	write(fd, header, 54);
	put_color_buff(buffer, &bmp, data);
	write(fd, buffer, bmp.image_size);
	close(fd);
	free(buffer);
	return (1);
}
