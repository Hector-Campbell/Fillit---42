/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 14:54:49 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/20 02:37:45 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	k = 0;
	if (!*needle)
		return ((char *)haystack);
	k = ft_strlen((char *)needle);
	while ((haystack[i]) && (i + k <= len))
	{
		if (haystack[i] == *needle)
		{
			j = ft_strncmp(haystack + i, needle, k);
			if (j == 0)
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
