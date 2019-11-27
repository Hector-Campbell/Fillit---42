/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 16:22:47 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/19 13:13:40 by vdauverg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	int			fd;
	char		**map;
	t_block		pos;
	t_tetrimino **tetriminos;

	if (argc == 2)
	{
		((fd = open(argv[1], O_RDONLY)) <= 0) ? safe_exit(0) : 0;
		if (!(tetriminos = read_input(fd)))
			safe_exit(0);
		pos.x = 0;
		pos.y = 0;
		map = map_init(tetriminos);
		map = iteration(map, tetriminos, 0, pos);
		ft_put2darray(map);
	}
	else
		safe_exit(-5);
	return (0);
}
