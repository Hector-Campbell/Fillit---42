/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 22:41:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/19 12:43:01 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		try_place(char ***map, t_tetrimino **tetriminos,
	int ti, t_block pos)
{
	int	ret;

	ret = 0;
	while (ret == 0)
	{
		ret = check_map(*map, tetriminos[ti], ti, &pos);
		pos.x++;
	}
	return (ret);
}

int		check_map(char **map, t_tetrimino *tetrimino, int ti, t_block *init)
{
	int		i;
	t_block	pos;

	first_block(map, init);
	pos.x = init->x;
	pos.y = init->y;
	i = 0;
	while (i++ < 4)
	{
		if ((!map[pos.y] || (!map[pos.y + 1] && !map[pos.y][pos.x])) \
			|| !(map[pos.y] && map[pos.y][pos.x] == '.'))
		{
			if (!map[pos.y] || (!map[pos.y + 1] && !map[pos.y][pos.x]))
				return (-1);
			else
				return (0);
		}
		pos = map_increment(tetrimino, pos, i);
	}
	map = place_tet(map, tetrimino, ti, *init);
	return (1);
}

char	**place_tet(char **map, t_tetrimino *tetrimino, int ti, t_block pos)
{
	char	letter;
	int		x;
	int		y;
	int		i;
	t_block	init;

	letter = 'A' + ti;
	init.x = tetrimino->blocks[0].x;
	init.y = tetrimino->blocks[0].y;
	i = 0;
	while (i < 4)
	{
		x = pos.x + tetrimino->blocks[i].x - init.x;
		y = pos.y + tetrimino->blocks[i].y - init.y;
		tetrimino->blocks[i].x = x;
		tetrimino->blocks[i].y = y;
		map[y][x] = letter;
		i++;
	}
	return (map);
}

t_block	find_points(char **map, int ti, t_block pos)
{
	int		x;
	int		y;
	char	letter;

	letter = 'A' + ti;
	x = 0;
	y = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] == letter)
			{
				pos.x = x;
				pos.y = y;
				return (pos);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (pos);
}

char	**unplace(char **map, t_tetrimino *tetrimino)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	while (i < 4)
	{
		x = tetrimino->blocks[i].x;
		y = tetrimino->blocks[i].y;
		if (map[y] && map[y][x])
			map[y][x] = '.';
		i++;
	}
	tetrimino->placed = 0;
	return (map);
}
