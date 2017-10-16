/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquesnot <gquesnot@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 04:07:04 by gquesnot          #+#    #+#             */
/*   Updated: 2017/10/16 15:44:22 by gquesnot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_tetrisrcircular(t_tetris **tetris_map)
{
	t_tetris			*tmp1;
	t_tetris			*tmp2;

	tmp1 = *tetris_map;
	tmp2 = tmp1->next;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	 tmp1->next = *tetris_map;
	 tmp1->next->next = NULL;
	 *tetris_map = tmp2;
}

void				ft_tetriscircular(t_tetris **tetris_map, int n1)
{
	t_tetris		*tmp1;
	t_tetris		*tmp2;
	t_tetris		*new;
	int				i;


	i = 0;
	tmp1 = *tetris_map;
	while (tmp1->next->next != NULL)
	{
		if (i == n1 - 1)
			tmp2 = tmp1;
		i++;
		tmp1 = tmp1->next;
	}
	new = tmp1->next;
	tmp1->next = NULL;
	new->next = tmp2->next;
	tmp2->next = new;
}



t_tetris			*ft_tetrisnew(int fd, int *error, int c)
{
	t_tetris		*new;

	if (!(new = malloc(1 * sizeof(t_tetris))))
		return (NULL);
	new->tab = ft_tab_to_coor(put_tetris_in_tab(fd, error));
	new->c = 'A' + c;
	new->next = NULL;
	return (new);
}

void			ft_tetrisadd(t_tetris **tetris_map, t_tetris *new)
{
	t_tetris		*tmp;

	tmp = *tetris_map;
	if (new)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
