/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 15:41:01 by hecampbe          #+#    #+#             */
/*   Updated: 2019/06/24 10:38:17 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			put_in_line(const int fd, char **str, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(str[fd], '\n')))
	{
		*tmp++ = '\0';
		*line = ft_strdup(str[fd]);
		tmp = ft_strdup(tmp);
		free(str[fd]);
		str[fd] = tmp;
	}
	else if ((tmp = ft_strchr(str[fd], '\0')))
	{
		*line = ft_strdup(str[fd]);
		ft_strdel(&str[fd]);
	}
	return (1);
}

static int			read_line(const int fd, char **str, char **line)
{
	char	*tmp;
	char	buffer[BUFF_SIZE + 1];
	int		amount;

	while ((amount = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[amount] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(0);
		tmp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (amount < 0)
		return (-1);
	if (BUFF_SIZE == 0)
		return (0);
	if (amount == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	else
		return (put_in_line(fd, str, line));
}

int					get_next_line(const int fd, char **line)
{
	static char *str[9999];

	if (!line || fd < 0)
		return (-1);
	return (read_line(fd, str, line));
}
