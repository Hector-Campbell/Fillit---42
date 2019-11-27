/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 13:26:28 by hecampbe          #+#    #+#             */
/*   Updated: 2019/04/09 04:27:09 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(char *src)
{
	char		*dst;
	int			i;
	int			len;

	i = 0;
	len = 0;
	len = ft_strlen(src);
	if (!(dst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	dst[len] = '\0';
	while (i <= len)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
