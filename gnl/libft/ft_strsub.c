/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 16:29:31 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/13 17:16:54 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	i = 0;
	if (!str)
		return (NULL);
	if (start > (unsigned int)ft_strlen((char *)str))
		return (NULL);
	if ((substr = (char *)malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len && str[start] != '\0')
	{
		substr[i] = str[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
