/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tetris.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gquesnot <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 13:18:47 by gquesnot     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:03:14 by gquesnot    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fillit.h"

void			ft_print_char(t_tetris *map)
{
	t_tetris	*tmp;

	tmp = map;
	while (tmp)
	{
		ft_putchar(tmp->c);
		ft_putchar(',');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

char			**ft_set_piece(t_tetris *tetris_map, char **tab)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		tab[tetris_map->tab[i].y + tetris_map->pos.y][tetris_map->tab[i].x \
			+ tetris_map->pos.x] = tetris_map->c;
		i++;
	}
	return (tab);
}

int				solve(t_tetris *tetris, char **tab, int size, int tab_size)
{
	if (tetris != NULL)
	{
		while (tetris->pos.y * tetris->pos.x < tab_size * tab_size)
		{
			if (ft_tetris_cat_issafe(tab, *tetris, tetris->pos, tab_size) == 1)
			{
				tab = ft_set_piece(tetris, tab);
				if (solve(tetris->next, tab, size, tab_size) == 1)
					return (1);
				ft_del_piece(tab, tetris->c, tab_size);
			}
			tetris->pos.x += 1;
			if (tetris->pos.x >= tab_size)
			{
				tetris->pos.x = 0;
				tetris->pos.y += 1;
			}
		}
		tetris->pos.x = 0;
		tetris->pos.y = 0;
		return (0);
	}
	return (1);
}

void			ft_del_piece(char **tab, char c, int tab_size)
{
	int			i;
	int			j;

	i = 0;
	while (i < tab_size)
	{
		j = 0;
		while (j < tab_size)
		{
			if (tab[i][j] == c)
				tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

char			**ft_tetris(t_tetris **tetris_map, int size)
{
	int			tab_size;
	char		**tab;

	tab_size = ft_next_square(4 * size, 0);
	tab = ft_malloc_char_tab(tab_size);
	ft_set_tab(tab, tab_size);
	while (!(solve(*tetris_map, tab, size, tab_size)))
	{
		tab_size++;
		tab = ft_malloc_char_tab(tab_size);
		ft_set_tab(tab, tab_size);
	}
	return (tab);
}
