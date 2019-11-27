/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:28:14 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/08 20:23:13 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strequ(char const *str1, char const *str2)
{
	int i;

	i = 0;
	if (str1 != NULL && str2 != NULL)
	{
		while (str1[i] == str2[i] && (str1[i] != '\0' && str2[i] != '\0'))
			i++;
		if (str1[i] == str2[i] && (str1[i] == '\0' && str2[i] == '\0'))
			return (1);
		else
			return (0);
	}
	else
		return (0);
}
