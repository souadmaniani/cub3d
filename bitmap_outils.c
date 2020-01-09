/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_outils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:53:41 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/06 19:51:51 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int				get_color_off_image(int x, int y)
{
	int			no;
	int			d;
	int			size_line;
	int			*img_set;
	int			color;

	img_set = (int*)mlx_get_data_addr(g_img, &no, &size_line, &d);
	color = img_set[y * (size_line / 4) + x];
	return (color);
}

void			decimal_to_rgb(int color, int *color1, int *color2, int *color3)
{
	*color1 = color % 256;
	*color2 = ((color - (*color1)) / 256) % 256;
	*color3 = ((color - (*color1)) / pow(256, 2)) - (*color2 / 256);
}
