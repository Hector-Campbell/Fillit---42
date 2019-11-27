/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 19:59:53 by vdauverg          #+#    #+#             */
/*   Updated: 2019/06/21 16:23:42 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		free_exit(t_tetrimino *tmp, t_tetrimino **tetriminos, \
				int num, int fd)
{
	(tmp) ? free(tmp) : 0;
	while (--num >= 0)
		free(tetriminos[num]);
	free(tetriminos);
	safe_exit(fd);
}

int			read_piece(int fd, t_tetrimino **tmp)
{
	int		i;
	int		len;
	int		res;
	char	*line;
	char	*piece;

	piece = "";
	i = 0;
	while ((res = get_next_line(fd, &line)) >= 0)
	{
		(*line) ? len = ft_strlen_2(line) : 0;
		if (*line && len == 4)
			piece = ft_strjoin(piece, line);
		else if (len == 4 && i == 4)
		{
			ft_strdel(&line);
			*tmp = check_piece(piece, fd);
			return ((res == 0) ? -1 : 1);
		}
		else
			return (0);
		(line) ? ft_strdel(&line) : 0;
		i++;
	}
	return (2);
}

t_tetrimino	**read_input(int fd)
{
	int			num;
	int			check;
	t_tetrimino	*tmp;
	t_tetrimino	**tetriminos;

	tetriminos = (t_tetrimino **)malloc(sizeof(t_tetrimino *) * 27);
	tetriminos[26] = NULL;
	num = 0;
	tmp = NULL;
	while ((check = read_piece(fd, &tmp)) != 2 || (check == 2 && num == 0))
	{
		if ((check == 1 || check == -1) && (tetriminos[num] = tmp))
		{
			if (check == -1 && ++num)
				break ;
		}
		else
			free_exit(tmp, tetriminos, num, fd);
		tmp = NULL;
		num++;
	}
	close(fd);
	while (num < 26)
		tetriminos[num++] = NULL;
	return (tetriminos);
}

int			ft_strlen_2(char *str)
{
	int i;

	i = 0;
	while (str[i] && (str[i] == '.' || str[i] == '#'))
		i++;
	return (i);
}
