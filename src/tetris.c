/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_res_tetris.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquesnot <gquesnot@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 01:26:45 by gquesnot          #+#    #+#             */
/*   Updated: 2017/10/16 16:13:04 by gquesnot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


void		ft_print_char(t_tetris *map)
{
	t_tetris *tmp;

	tmp = map;
	while (tmp)
	{
		ft_putchar(tmp->c);
		ft_putchar(',');
		tmp = tmp->next;
	}
	ft_putchar('\n');
}




int				ft_tetris_isvalid(char **tab, t_tetris *tetris_map ,int size)
{
	char		c;
	t_tetris	*tmp;
	int			i;

	i = 0;
	tmp = tetris_map;
	while (tmp && ft_tetris_cat(tab, *tmp, ft_strlen(*tab), tmp->c))
	{
		i++;
		c++;
		tmp = tmp->next;

	}
	if (i == size)
		return (1);
	else
		return (0);
}

int			ft_tetris3(t_tetris **tetris_map, char **tab, int size, int tab_size)
{
	int		i;
	int		j;

	i =  1;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			ft_print_char(*tetris_map);
			if (ft_tetris_isvalid(tab, *tetris_map, size))
				return (1);
			ft_set_tab(tab, tab_size);
			ft_tetriscircular(tetris_map, i);
			j++;
		}
		i++;
	}
	return (0);
}

int				ft_tetris2(t_tetris **tetris_map, char **tab, int size, int tab_size)
{
	int			i;

	i = 0;
	while (i < size)
	{
		ft_set_tab(tab, tab_size);
		ft_tetris3(tetris_map, tab, size, tab_size);
		ft_set_tab(tab, tab_size);
		if (ft_tetris_isvalid(tab, *tetris_map, size))
			return (1);
		ft_tetrisrcircular(tetris_map);
		ft_print_char(*tetris_map);
		i++;
	}
	return (0);
}

char			**ft_tetris(t_tetris **tetris_map, int size)
{
	int			tab_size;
	char		**tab;


	tab_size = ft_next_square(4 * size, 0);
	tab = ft_malloc_char_tab(tab_size);
	while (!(ft_tetris2(tetris_map, tab, size, tab_size)))
	{
		tab_size++;
		tab = ft_malloc_char_tab(tab_size);
	}
	return (tab);
}
