/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_param.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gquesnot <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 13:18:21 by gquesnot     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 13:59:28 by gquesnot    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void			ft_read_tetris(t_tetris *elem, int size)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (i < size)
	{
		while (j < 4)
		{
			ft_putnbr(elem->tab[j].y);
			ft_putchar(',');
			ft_putnbr(elem->tab[j].x);
			ft_putchar('\n');
			j++;
		}
		i++;
	}
	ft_putchar('\n');
}

t_coor			*ft_tab_to_coor(char **tab)
{
	int			i;
	int			j;
	int			k;
	t_coor		*array;

	i = 0;
	k = 0;
	array = malloc(4 * sizeof(t_coor));
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tab[i][j] == '#')
			{
				array[k].x = j;
				array[k].y = i;
				k++;
			}
			j++;
		}
		i++;
	}
	return (array);
}

char			**ft_malloc_char_tab(int size)
{
	int			i;
	char		**tab;

	i = 0;
	tab = malloc((size + 1) * sizeof(char*));
	while (i < size)
	{
		tab[i] = ft_strnew(size);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

char			**put_tetris_in_tab(int fd, int *error)
{
	int			i;
	char		**tab;
	char		*line;

	i = 0;
	tab = ft_malloc_char_tab(4);
	while (*error > 0 && i < 4)
	{
		*error = get_next_line(fd, &line);
		tab[i] = ft_strdup(line);
		i++;
	}
	return (tab);
}

int				ft_params_to_struct(t_tetris **tetris_map, char **av, int size)
{
	int			fd;
	t_tetris	*tmp;
	int			error;
	int			i;

	error = 1;
	i = 0;
	*tetris_map = malloc(sizeof(t_tetris));
	tmp = malloc(sizeof(t_tetris));
	if (!(fd = open(av[1], O_RDONLY)))
		return (0);
	*tetris_map = ft_tetrisnew(fd, &error, i);
	i++;
	while (error > 0 && i < size)
	{
		tmp = ft_tetrisnew(fd, &error, i);
		ft_tetrisadd(tetris_map, tmp);
		i++;
	}
	close(fd);
	return (1);
}
