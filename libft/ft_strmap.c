/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 15:30:28 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/08 20:37:45 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *str, char (*f)(char))
{
	int		i;
	char	*fstr;

	i = 0;
	if (!str || !f || !*f)
		return (NULL);
	fstr = ft_strnew(ft_strlen((char *)str));
	if (fstr == NULL)
		return (NULL);
	while (str[i])
	{
		fstr[i] = f(str[i]);
		i++;
	}
	fstr[i] = '\0';
	return (fstr);
}
