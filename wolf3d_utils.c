/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 21:46:26 by smaniani          #+#    #+#             */
/*   Updated: 2019/12/27 23:52:58 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			normalize_angl(t_ray *ray)
{
	ray->ray_angl = fmod(ray->ray_angl, 2 * M_PI);
	if (ray->ray_angl < 0)
		ray->ray_angl = 2 * M_PI + ray->ray_angl;
}

int				rayfacingdown(t_ray *ray)
{
	if (ray->ray_angl > 0 && ray->ray_angl < M_PI)
		return (1);
	return (0);
}

int				rayfacingup(t_ray *ray)
{
	if (!(ray->ray_angl > 0 && ray->ray_angl < M_PI))
		return (1);
	return (0);
}

int				rayfacingreight(t_ray *ray)
{
	if (ray->ray_angl < M_PI / 2 || ray->ray_angl > 3 * M_PI / 2)
		return (1);
	return (0);
}

int				rayfacingleft(t_ray *ray)
{
	if (!(ray->ray_angl < M_PI / 2 || ray->ray_angl > 3 * M_PI / 2))
		return (1);
	return (0);
}
