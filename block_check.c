/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:44:17 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/19 11:43:06 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_block	map_increment(t_tetrimino *tetriminos, t_block pos, int i)
{
	int x;
	int y;
	int tmp_x;
	int tmp_y;

	tmp_x = tetriminos->blocks[i - 1].x;
	tmp_y = tetriminos->blocks[i - 1].y;
	x = tetriminos->blocks[i].x;
	y = tetriminos->blocks[i].y;
	if (y > tmp_y)
		pos.y++;
	if (x > tmp_x)
		pos.x++;
	if (x < tmp_x)
		pos.x--;
	if (x < tmp_x && x < tmp_x - 1)
		pos.x--;
	return (pos);
}

char	**first_block(char **map, t_block *pos)
{
	int	x;
	int	y;

	x = pos->x;
	y = pos->y;
	while (map[y] && map[y][x] != '.')
	{
		x++;
		if (!map[y][x])
		{
			x = 0;
			y++;
		}
	}
	pos->x = x;
	pos->y = y;
	return (map);
}
