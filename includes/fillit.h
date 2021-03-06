/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fillit.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gquesnot <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/20 13:22:01 by gquesnot     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 13:25:29 by gquesnot    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct s_coor		t_coor;
typedef struct s_tetris	t_tetris;

struct				s_coor
{
	int				x;
	int				y;
};

struct				s_tetris
{
	t_coor			*tab;
	char			c;
	t_coor			pos;
	t_tetris		*next;
};

t_tetris			*ft_cut_tetris(t_tetris **elem);
char				**put_tetris_in_tab(int fd, int *error);
t_tetris			*ft_tetrisnew(int fd, int *error, int c);
void				ft_tetrisadd(t_tetris **tetris_map, t_tetris *new);
int					ft_params_to_struct(t_tetris **tetris_map, char **av, \
		int size);
void				ft_read_tetris(t_tetris *elem, int size);
t_coor				*ft_tab_to_coor(char **tab);
int					ft_check_file(char **av, int *size);
int					ft_check_tetriminos(t_tetris *elem);
int					ft_tetris_cat(char **tab, t_tetris elem, int size, char c);
char				**ft_malloc_char_tab(int size);
void				ft_tetriscircular(t_tetris **tetris_map, int n1);
void				ft_tetrisrcircular(t_tetris **tetris_map);
int					ft_tetris_isvalid(char **tab, t_tetris *tetris_map \
		, int size);
char				**ft_set_tab(char **tab, int tab_size);
int					ft_tetris_isvalid(char **tab, t_tetris *tetris_map, \
		int size);
char				**ft_tetris(t_tetris **tetris_map, int size);
void				ft_print_tab(char **tab);
int					ft_tetris2(t_tetris **tetris_map, char **tab, int size, \
		int tab_size);
int					ft_next_square(int nb, int next);
int					ft_tetris_cat_issafe(char **tab, t_tetris elem, \
		t_coor coor, int size);
void				ft_del_piece(char **tab, char c, int tab_size);
void				ft_print_char(t_tetris *map);

#endif
