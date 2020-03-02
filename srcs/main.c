/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jesmith <jesmith@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 16:47:39 by mminkjan       #+#    #+#                */
/*   Updated: 2019/04/09 18:23:11 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_print_grid(t_grid play)
{
	size_t		i;

	i = 0;
	while (i < play.grid_size)
	{
		write(1, play.grid[i], play.grid_size);
		ft_putchar('\n');
		i++;
	}
}

static t_tet	*clear_coordinates(t_tet **minos)
{
	t_tet		*head;
	int			y;
	int			x;

	x = 0;
	y = 0;
	head = *minos;
	while (*minos != NULL)
	{
		(*minos)->y = y;
		(*minos)->x = x;
		(*minos) = (*minos)->next;
	}
	*minos = head;
	return (*minos);
}

static void		start_algo(t_tet **minos, t_tet **head, t_grid start)
{
	while (*minos != NULL)
	{
		if (start.check == 0)
		{
			*minos = (*minos)->next;
			if (*minos == NULL)
			{
				ft_print_grid(start);
				exit(0);
			}
			(*minos)->x = 0;
			(*minos)->y = 0;
			start.check = -1;
			start = filling_grid(&*minos, &*head, start);
		}
		if (start.check == -1)
		{
			*minos = clear_coordinates(&*minos);
			start.grid_size++;
			start = filling_grid(&*minos, &*head, start);
		}
	}
	ft_print_grid(start);
	exit(0);
}

static t_grid	ft_grid(void)
{
	t_grid	start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < 17)
	{
		while (j < 17)
		{
			start.grid[i][j] = '.';
			j++;
		}
		start.grid[i][j] = '\n';
		j = 0;
		i++;
	}
	i = 0;
	start.check = -1;
	start.grid_size = 1;
	return (start);
}

int				main(int argc, char **argv)
{
	t_tet		*minos;
	t_tet		*head;
	t_grid		start;

	if (argc != 2)
	{
		write(1, "usage: input valid file sample.txt\n", 35);
		exit(0);
	}
	if (save_valid(argv[1], &minos) != 0)
	{
		write(1, "error\n", 6);
		exit(0);
	}
	head = minos;
	start = ft_grid();
	start_algo(&minos, &head, start);
	exit(0);
}
