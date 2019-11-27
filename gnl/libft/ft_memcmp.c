/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:19:48 by hecampbe          #+#    #+#             */
/*   Updated: 2019/04/09 04:07:00 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *str1, const void *str2, size_t len)
{
	size_t			i;
	unsigned char	*str11;
	unsigned char	*str22;

	i = 0;
	str11 = (unsigned char *)str1;
	str22 = (unsigned char *)str2;
	if (str22 == str11 || len == 0)
		return (0);
	while (i < len)
	{
		if (str22[i] != str11[i])
			return (str11[i] - str22[i]);
		i++;
	}
	return (0);
}
