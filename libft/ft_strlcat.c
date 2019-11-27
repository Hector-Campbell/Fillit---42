/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 21:15:39 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/12 18:12:43 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t end;

	i = 0;
	j = 0;
	if (size <= ft_strlen(dst))
		return (ft_strlen((char *)src) + size);
	while (dst[i] && i < size)
		i++;
	end = i;
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (end < size)
		dst[i] = '\0';
	return (end + ft_strlen((char *)src));
}
