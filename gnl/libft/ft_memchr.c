/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:06:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/08 00:03:36 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *str1, int c, size_t len)
{
	size_t			i;
	const char		*str2;
	char			ch;

	i = 0;
	str2 = str1;
	ch = c;
	while (i < len)
	{
		if (str2[i] == ch)
			return ((void *)&str2[i]);
		else
			i++;
	}
	return (NULL);
}
