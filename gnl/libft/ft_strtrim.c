/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:10:27 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/26 02:10:07 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	if (!str)
		return (0);
	i = -1;
	j = 0;
	len = ft_strlen((char *)str);
	while ((str[len - 1] == ' ' || str[len - 1] == '\t' ||
				str[len - 1] == '\n') && len > 1)
		len--;
	while (str[++i] == ' ' || str[i] == '\t' || str[i] == '\n')
		len--;
	if (len < 0)
		len = 0;
	if (!(new = (char *)malloc(sizeof(char) * (len) + 1)))
		return (0);
	while (j < len)
		new[j++] = str[i++];
	new[j] = '\0';
	return (new);
}
