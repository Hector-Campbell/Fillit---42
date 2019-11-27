/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 18:32:43 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/10 15:27:54 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, char *src, size_t len)
{
	size_t	i;
	int		end;

	i = 0;
	end = 0;
	while (i < len)
	{
		if (src[i] && !end)
			dst[i] = src[i];
		else
		{
			dst[i] = '\0';
			end = 1;
		}
		i++;
	}
	return (dst);
}
