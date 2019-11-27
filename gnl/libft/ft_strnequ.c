/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 01:00:01 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/26 05:10:16 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *str1, char const *str2, size_t n)
{
	size_t		i;

	if (!n)
		return (1);
	if (str1 && str2 && n)
	{
		i = 0;
		while (n > 0)
		{
			if (str1[i] != str2[i])
				return (0);
			i++;
			n--;
		}
		return (1);
	}
	return (0);
}
