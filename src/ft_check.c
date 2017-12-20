/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_check.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gquesnot <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 13:18:08 by gquesnot     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 13:42:41 by gquesnot    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

int				ft_check_tetriminos2(t_tetris elem, t_coor to_find)
{
	int			res;
	int			i;

	res = 0;
	i = 0;
	while (i < 4)
	{
		if (elem.tab[i].x == to_find.x && (elem.tab[i].y == to_find.y + 1 || \
					elem.tab[i].y == to_find.y - 1))
			res++;
		if (elem.tab[i].y == to_find.y && (elem.tab[i].x == to_find.x + 1 || \
					elem.tab[i].x == to_find.x - 1))
			res++;
		i++;
	}
	return (res);
}

int				ft_check_tetriminos(t_tetris *elem)
{
	int			i;
	int			res;

	while (elem)
	{
		i = 0;
		res = 0;
		while (i < 4)
		{
			res += ft_check_tetriminos2(*elem, elem->tab[i]);
			i++;
		}
		if (res < 5)
			return (0);
		elem = elem->next;
	}
	return (1);
}

int				ft_check_size_and_char(char *buff)
{
	int			i;
	int			k;

	k = 0;
	i = 0;
	while (i < 20)
	{
		if (buff[i] != '.' && buff[i] != '#' && buff[i] != '\n')
			return (0);
		else
		{
			if (buff[i] == '#')
				k += 1;
		}
		i++;
		if (buff[i] == '\n')
		{
			i++;
			if (i % 5 != 0)
				return (0);
		}
	}
	if (k != 4)
		return (0);
	return (1);
}

int				ft_check_file(char **av, int *size)
{
	int			fd;
	char		*buff;
	int			error;

	error = 1;
	buff = ft_strnew(10);
	fd = open(av[1], O_RDONLY);
	if (!fd)
		return (0);
	while (error > 0)
	{
		error = read(fd, buff, 20);
		if (!(ft_check_size_and_char(buff)))
			return (0);
		error = read(fd, buff, 1);
		ft_bzero(buff, 21);
		*size += 1;
	}
	close(fd);
	return (1);
}
