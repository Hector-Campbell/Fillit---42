/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteration.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:17:27 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/19 12:38:36 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**iteration(char **map, t_tetrimino **tetriminos, int ti, \
				t_block pos)
{
	int	check;

	while (1)
	{
		check = iteration_checks(map, tetriminos, ti, pos);
		if (check == -1 && !(pos.x = 0) \
			&& !(pos.y = 0))
			map = map_increase(map);
		else
			break ;
	}
	return (map);
}

int		iteration_checks(char **map, t_tetrimino **tetriminos, int ti, \
				t_block pos)
{
	int	check;

	while ((check = try_place(&map, tetriminos, ti, pos)))
	{
		if (check == 1)
		{
			pos.x = 0;
			pos.y = 0;
			tetriminos[ti]->placed = 1;
			if (!tetriminos[++ti])
				break ;
		}
		else
		{
			pos = prep_mappos(tetriminos[ti], map, pos);
			if (!map[pos.y])
			{
				if (!ti)
					break ;
				pos = find_points(map, --ti, pos);
				pos = prep_mappos(tetriminos[ti], map, pos);
			}
		}
	}
	return (check);
}

t_block	prep_mappos(t_tetrimino *tetrimino, char **map, t_block pos)
{
	if (tetrimino->placed == 1)
		map = unplace(map, tetrimino);
	pos.x++;
	if (!map[pos.y][pos.x])
	{
		pos.y++;
		pos.x = 0;
	}
	return (pos);
}

char	**map_increase(char **map)
{
	int		j;
	int		i;
	int		map_size;
	char	**new_map;

	map_size = ft_strlen(map[0]);
	j = 0;
	i = map_size;
	new_map = (char **)malloc(sizeof(char *) * (++map_size + 1));
	new_map[map_size] = NULL;
	while (j < i)
	{
		new_map[j] = (char *)malloc(sizeof(char) * (map_size + 1));
		new_map[j][map_size] = '\0';
		new_map[j] = ft_strcpy(new_map[j], map[j]);
		new_map[j][i] = '.';
		j++;
	}
	new_map[j] = (char *)malloc(sizeof(char) * (map_size + 1));
	i = -1;
	while (++i < map_size)
		new_map[j][i] = '.';
	new_map[j][i] = '\0';
	map_del(map);
	return (new_map);
}

void	map_del(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}
