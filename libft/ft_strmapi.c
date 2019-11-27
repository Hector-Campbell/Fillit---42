/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 01:20:53 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/08 19:50:01 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fstr;

	i = 0;
	if (!str || !f)
		return (NULL);
	fstr = ft_strnew(ft_strlen((char *)str));
	if (fstr == NULL)
		return (NULL);
	while (str[i])
	{
		fstr[i] = (*f)(i, str[i]);
		i++;
	}
	return (fstr);
}
