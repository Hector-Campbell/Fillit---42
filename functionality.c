/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionality.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:14:23 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/19 13:14:34 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	safe_exit(int fd)
{
	if (fd == -5)
		ft_putendl("usage: ./fillit source_file");
	else
	{
		(fd) ? close(fd) : 0;
		ft_putendl("error");
	}
	exit(0);
}

int		square_root(int num)
{
	int	i;

	i = 1;
	if (num <= 1)
		return (num);
	if (num == 4)
		return (2);
	while ((i * i) < num)
		i++;
	return (i);
}

char	**map_init(t_tetrimino **tetriminos)
{
	int		i;
	int		j;
	int		num;
	char	**map;

	num = 0;
	while (tetriminos[num])
		num++;
	num = square_root(num * 4);
	map = (char **)malloc(sizeof(char *) * (num + 1));
	map[num] = NULL;
	i = 0;
	while (i < num)
	{
		map[i] = (char *)malloc(sizeof(char) * (num + 1));
		map[i][num] = 0;
		j = 0;
		while (j < num)
		{
			map[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_put2darray(char **map)
{
	int j;

	j = 0;
	while (map[j])
	{
		ft_putendl(map[j]);
		j++;
	}
}
