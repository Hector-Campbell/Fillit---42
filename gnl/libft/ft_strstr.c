/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:16:48 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/01 01:13:14 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	k = ft_strlen((char *)needle);
	if (k == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			j = ft_strncmp(haystack + i, needle, k);
			if (j == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
