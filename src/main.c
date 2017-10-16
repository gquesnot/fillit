/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquesnot <gquesnot@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 04:35:25 by gquesnot          #+#    #+#             */
/*   Updated: 2017/10/16 13:03:38 by gquesnot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			ft_print_tab(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return;
	while (tab[i])
	{
		ft_putendl(tab[i]);
		i++;
	}
}

char			**ft_set_tab(char **tab, int tab_size)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < tab_size)
	{
		while (j < tab_size)
		{
			tab[i][j] = '.';
			j++;
		}
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int				main(int ac, char **av)
{
	int			size;
	t_tetris	*tetris_map;
	int			map_error;
	char		**tab;

	size = 0;
	tab = ft_malloc_char_tab(4);
	map_error = ft_check_file(av, &size);
	ft_set_tab(tab, 4);
	ft_params_to_struct(&tetris_map, av, size);
	tetris_map = ft_cut_tetris(&tetris_map);
	map_error *= ft_check_tetriminos(tetris_map);
	if (map_error == 0 || ac != 2)
	{
		ft_putendl("error");
		return (0);
	}
	ft_print_tab(ft_tetris(&tetris_map, size));
	return (0);
}
