/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   manage_grid.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/22 18:28:34 by mminkjan       #+#    #+#                */
/*   Updated: 2019/04/09 18:24:42 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_grid	ft_remove_letter(t_tet **minos, t_grid play)
{
	size_t	y;
	size_t	x;

	y = 0;
	x = 0;
	while (y < play.grid_size)
	{
		while (x < play.grid_size)
		{
			if (play.grid[y][x] == (char)(*minos)->content_size)
				play.grid[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
	return (play);
}

t_tet			*minos_previous(t_tet **minos, t_tet **head)
{
	size_t	sign;

	sign = (*minos)->content_size;
	*minos = *head;
	if (sign != 65)
	{
		while (*minos != NULL)
		{
			if ((*minos)->content_size == (sign - 1))
				return (*minos);
			*minos = (*minos)->next;
		}
	}
	return (*minos);
}

static t_tet	*next_free_position(t_grid grid, t_tet **minos)
{
	while ((*minos)->y < grid.grid_size)
	{
		while ((size_t)(*minos)->x < grid.grid_size)
		{
			if (grid.grid[(*minos)->y][(*minos)->x] == '.')
				return (*minos);
			(*minos)->x++;
		}
		(*minos)->y++;
		(*minos)->x = 0;
	}
	(*minos)->x = -1;
	return (*minos);
}

t_grid			filling_grid(t_tet **minos, t_tet **head, t_grid play)
{
	while (play.check == -1 && (*minos)->x != -1)
	{
		*minos = next_free_position(play, &*minos);
		play = set_tetros_grid(&*minos, play);
		if ((*minos)->x == -1)
			break ;
		if (play.check != -1)
			return (play);
		(*minos)->x++;
	}
	if ((*minos)->x == -1)
	{
		*minos = minos_previous(&*minos, &*head);
		if ((*minos)->content_size == 65 && (*minos)->x == -1)
		{
			play.check = -1;
			return (play);
		}
		(*minos)->x++;
		play = ft_remove_letter(&*minos, play);
		return (filling_grid(&*minos, &*head, play));
	}
	return (filling_grid(&*minos, &*head, play));
}
