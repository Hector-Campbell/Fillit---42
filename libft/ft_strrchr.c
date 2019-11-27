/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 12:46:05 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/11 19:39:11 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen((char *)str);
	while (i != 0)
	{
		if (str[i] == c)
			return ((char *)&str[i]);
		i--;
	}
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}
