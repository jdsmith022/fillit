/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setting_tetros.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/11 17:11:56 by jesmith        #+#    #+#                */
/*   Updated: 2019/04/09 18:42:41 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_grid		remove_edit(t_tet **minos, t_grid play)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (i <= play.grid_size)
	{
		j = 0;
		while (j <= play.grid_size)
		{
			if (play.grid[i][j] == (char)(*minos)->content_size)
				play.grid[i][j] = '.';
			j++;
		}
		i++;
	}
	play.check = -1;
	return (play);
}

static t_grid		placing_tetros(t_tet **minos, t_grid play, int i,
					t_pos cal)
{
	char *tetro;

	tetro = (*minos)->content;
	while (tetro[i] != '\0')
	{
		if (tetro[i] == '#')
		{
			cal.set = ((int)i - cal.correction) - cal.diff;
			if (cal.set < 0 || (size_t)cal.set > (play.grid_size - 1) ||
			play.grid[cal.y][cal.set] != '.' || cal.y > (play.grid_size - 1))
			{
				play = remove_edit(&*minos, play);
				return (play);
			}
			play.grid[cal.y][cal.set] = ((char)(*minos)->content_size);
		}
		if (tetro[i] == '\n')
		{
			cal.y++;
			cal.correction = cal.correction + 5;
		}
		i++;
	}
	play.check = 0;
	return (play);
}

t_grid				set_tetros_grid(t_tet **minos, t_grid play)
{
	size_t			i;
	t_pos			cal;
	char			*tetro;

	i = 0;
	cal.correction = 0;
	tetro = (*minos)->content;
	cal.y = (int)(*minos)->y;
	while (tetro[i] != '#' && tetro[i] != '\0')
	{
		if (tetro[i] == '\n')
			cal.correction = cal.correction - 5;
		i++;
	}
	cal.diff = ((int)i - cal.correction) - (int)(*minos)->x;
	play = placing_tetros(&*minos, play, i, cal);
	return (play);
}
