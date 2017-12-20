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

t_tetris			*ft_tetrisnew(int fd, int *error, int c)
{
	t_tetris		*new;

	if (!(new = malloc(1 * sizeof(t_tetris))))
		return (NULL);
	new->tab = ft_tab_to_coor(put_tetris_in_tab(fd, error));
	new->c = 'A' + c;
	new->pos.x = 0;
	new->pos.y = 0;
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
