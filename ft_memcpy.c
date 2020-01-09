/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:41:38 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/06 17:05:23 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char			*dest1;
	const unsigned char		*src1;
	size_t					i;

	dest1 = (unsigned char*)dest;
	src1 = (const unsigned char*)src;
	i = 0;
	if (dest1 == src1)
		return (dest);
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest);
}
