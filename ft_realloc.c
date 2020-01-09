/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 16:59:56 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/08 07:42:33 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_bzero(void *s, size_t n)
{
	unsigned long i;
	unsigned char *tab;

	i = 0;
	tab = s;
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
}

unsigned char	*ft_realloc(unsigned char *buffer, int old_size, int new_size)
{
	unsigned char		*ptr;
	int					i;

	i = 0;
	(void)old_size;
	if (!(ptr = (unsigned char*)malloc(new_size)))
		return (NULL);
	ft_bzero(ptr, new_size);
	free(buffer);
	return (ptr);
}
