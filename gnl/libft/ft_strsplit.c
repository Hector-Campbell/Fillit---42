/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 13:21:18 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/25 19:44:58 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_words(char const *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	return (count + 1);
}

static int		count(char const *str, char c, int i)
{
	int count;

	count = 0;
	while (str[i] != c && str[i])
	{
		i++;
		count++;
	}
	return (count + 1);
}

static int		indexcount(char const *str, char c, int i)
{
	while (str[i] == c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *str, char c)
{
	int		i;
	int		j;
	int		k;
	char	**split;

	if (!str)
		return (NULL);
	if (!(split = (char **)malloc(sizeof(char*) * ft_get_words(str, c))))
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		k = 0;
		i = indexcount(str, c, i);
		if (str[i])
		{
			split[j] = (char *)malloc(sizeof(char) * count(str, c, i));
			while (str[i] != c && str[i])
				split[j][k++] = str[i++];
			split[j++][k] = '\0';
		}
	}
	split[j] = 0;
	return (split);
}
