/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fillit.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 16:53:23 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/02 13:43:28 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../libft/libft.h"
# include <fcntl.h>

typedef	struct		s_tet
{
	void			*content;
	size_t			y;
	ssize_t			x;
	size_t			content_size;
	struct s_tet	*next;
}					t_tet;
typedef struct		s_grid
{
	char			grid[17][17];
	size_t			grid_size;
	int				check;
}					t_grid;
typedef struct		s_pos
{
	int				diff;
	int				correction;
	int				set;
	size_t			y;
}					t_pos;
t_tet				*ft_tetnew(void const *content, size_t content_size,
					size_t sign);
void				ft_tetback(t_tet **alst, t_tet *blst);
int					save_valid(const char *file, t_tet **minos);
t_grid				filling_grid(t_tet **minos, t_tet **head, t_grid play);
t_grid				set_tetros_grid(t_tet **minos, t_grid play);

#endif
