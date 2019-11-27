/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 12:14:33 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/06 19:40:12 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (!(dst = (char *)malloc(size)))
		return (NULL);
	while (i < size)
		dst[i++] = '\0';
	return (dst);
}
