/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 13:06:36 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/07 23:07:48 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *str1, int c, size_t len)
{
	size_t			i;
	char			*str2;
	unsigned char	ch;

	i = 0;
	str2 = str1;
	ch = c;
	while (i < len)
	{
		str2[i] = ch;
		i++;
	}
	return ((char *)str1);
}
