/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:31:09 by hecampbe          #+#    #+#             */
/*   Updated: 2019/04/09 04:09:03 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t len)
{
	size_t			i;
	char			*dest;
	const char		*source;

	i = 0;
	dest = dst;
	source = src;
	while (i < len)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
