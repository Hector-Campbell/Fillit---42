/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 13:09:04 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/20 02:16:45 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i]
				&& s1[i] != '\0' && s2[i] != '\0') && (i < len - 1))
		i++;
	if (len == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
