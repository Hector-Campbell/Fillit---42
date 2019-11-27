/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:47:04 by hecampbe          #+#    #+#             */
/*   Updated: 2019/07/20 14:41:37 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*newstr;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	if ((newstr = (char *)malloc(ft_strlen((char *)str1)
					+ ft_strlen((char *)str2) + 1)) == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		newstr[i] = str1[i];
		i++;
	}
	while (str2[j])
	{
		newstr[i] = str2[j];
		j++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
