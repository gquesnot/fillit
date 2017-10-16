/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fttetri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquesnot <gquesnot@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 16:04:48 by gquesnot          #+#    #+#             */
/*   Updated: 2017/10/16 16:19:08 by gquesnot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int				ft_next_square(int nb, int next)
{
	int			i;

	i = 1;
	while (i * i < nb)
		i++;
	i += next;
	return (i);
}


t_tetris		*ft_cut_tetris(t_tetris **elem)
{
	int			i;
	t_tetris	*tmp;

	i = 0;
	tmp = *elem;
	while (tmp)
	{
		while (tmp->tab[0].x > 0 && tmp->tab[1].x > 0 && tmp->tab[2].x > 0 \
				&& tmp->tab[3].x > 0)
		{
			while (i < 4)
				tmp->tab[i++].x--;
			i = 0;
		}
		while (tmp->tab[0].y > 0 && tmp->tab[1].y > 0 && tmp->tab[2].y > 0 \
				&& tmp->tab[3].y > 0 && i < 4)
		{
			while (i < 4)
				tmp->tab[i++].y--;
			i = 0;
		}
		tmp = tmp->next;
	}
	return (*elem);
}

int				ft_tetris_cat_issafe(char **tab, t_tetris elem, \
		t_coor coor, int size)
{
	int			i;

	i = 0;
	while (i < 4)
	{
		if (coor.y + elem.tab[i].y >= size || coor.x + elem.tab[i].x >= size)
			return (0);
		if (tab[coor.y + elem.tab[i].y][coor.x + elem.tab[i].x] != '.')
			return (0);
		i++;
	}
	return (1);
}

void			ft_tetris_cpy(char **tab, t_tetris elem, t_coor coor, char c)
{
	int			i;

	i = 0;
	while (i < 4)
	{			
		tab[coor.y + elem.tab[i].y][coor.x + elem.tab[i].x] = c;
		i++;
	}
}


int				ft_tetris_cat(char **tab, t_tetris elem, int size, char c)
{
	t_coor		coor;

	coor.x = 0;
	coor.y = 0;
	while (coor.y < size)
	{
		while (coor.x < size)
		{
			if (ft_tetris_cat_issafe(tab, elem, coor, size))
			{
				ft_tetris_cpy(tab, elem ,coor, c);
				return (1);
			}
			coor.x++;
		}
		coor.x = 0;
		coor.y++;
	}
	return (0);
}


