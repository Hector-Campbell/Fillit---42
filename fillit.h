/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdauverg <vdauverg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 09:15:45 by vdauverg          #+#    #+#             */
/*   Updated: 2019/11/27 14:02:24 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct	s_block
{
	int		x;
	int		y;
}				t_block;

typedef struct	s_tetrimino
{
	t_block	*blocks;
	int		placed;
}				t_tetrimino;

void			ft_put2darray(char **map);
void			safe_exit(int fd);
char			**map_init(t_tetrimino **tetriminos);
int				square_root(int num);
t_tetrimino		**read_input(int fd);
int				read_piece(int fd, t_tetrimino **tmp);
void			free_exit(t_tetrimino *tmp, t_tetrimino **tetriminos, \
				int num, int fd);
int				find_adjacent_blocks(t_block *blocks, int i);
t_tetrimino		*check_blocks(t_block *blocks, int fd);
t_tetrimino		*check_piece(char *piece, int fd);
int				check_map(char **map, t_tetrimino *tetriminos, \
					int ti, t_block *init);
char			**place_tet(char **map, t_tetrimino *tetrimino, \
					int ti, t_block pos);
char			**unplace(char **map, t_tetrimino *tetrimino);
t_block			find_points(char **map, int ti, t_block points);
int				try_place(char ***map, t_tetrimino **tetriminos, int ti, \
					t_block pos);
t_block			map_increment(t_tetrimino *tetriminos, t_block pos, int i);
char			**first_block(char **map, t_block *pos);
char			**iteration(char **map, t_tetrimino **tetriminos, int ti, \
					t_block pos);
char			**map_increase(char **map);
void			map_del(char **map);
t_block			prep_mappos(t_tetrimino *tetrimino, char **map, t_block pos);
int				iteration_checks(char **map, t_tetrimino **tetriminos, int ti, \
					t_block pos);
int				ft_strlen_2(char *str);
#endif
