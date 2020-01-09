/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smaniani <smaniani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 19:12:07 by smaniani          #+#    #+#             */
/*   Updated: 2020/01/05 17:56:50 by smaniani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

char		*ft_strdup(const char *src)
{
	int		i;
	int		lentgh;
	char	*duplicate;

	i = 0;
	duplicate = NULL;
	lentgh = ft_strlen(src);
	duplicate = (char*)malloc((lentgh + 1) * sizeof(char));
	if (duplicate)
	{
		while (i < lentgh)
		{
			duplicate[i] = src[i];
			i++;
		}
		duplicate[i] = '\0';
	}
	return (duplicate);
}
