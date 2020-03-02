/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validate_file.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/04 19:31:20 by mminkjan       #+#    #+#                */
/*   Updated: 2019/04/15 18:22:24 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_connections(t_tet *tet, size_t connect_count)
{
	size_t		i;
	size_t		hash_count;

	i = 0;
	hash_count = 0;
	while (((char*)tet->content)[i] != '\0')
	{
		if (((char*)tet->content)[i] == '#')
		{
			if (((char*)tet->content)[i + 1] == '#')
				connect_count++;
			if (((char*)tet->content)[i + 5] == '#')
				connect_count++;
			if (((char*)tet->content)[i - 1] == '#')
				connect_count++;
			if (((char*)tet->content)[i - 5] == '#')
				connect_count++;
			hash_count++;
		}
		i++;
	}
	if (hash_count == 4 && (connect_count == 6 || connect_count == 8))
		return (0);
	return (-1);
}

static int		ft_check_grid(t_tet *tet)
{
	size_t		line_count;
	size_t		char_count;
	char		*temp;
	size_t		new_index;
	size_t		connect_count;

	temp = tet->content;
	char_count = 0;
	line_count = 0;
	connect_count = 0;
	new_index = 4;
	while (temp[char_count] == '.' || temp[char_count] == '#')
	{
		char_count++;
		if (char_count == new_index && temp[new_index] == '\n')
		{
			line_count++;
			new_index = (new_index + 5);
			char_count++;
		}
	}
	if (line_count == 4 && char_count == 20 && (temp[char_count] == '\n'
	|| temp[char_count + 1] == '\0' || temp[char_count] == '\0'))
		return (ft_check_connections(tet, connect_count));
	return (-1);
}

static int		ft_lst_creator(char *temp, t_tet **minos)
{
	t_tet			*tet;
	static size_t	sign = 65;

	tet = ft_tetnew(temp, 22, sign);
	free(temp);
	if (!tet)
		return (-1);
	ft_tetback(&*minos, tet);
	if (ft_check_grid(tet) == -1)
		return (-1);
	sign++;
	if (sign > 91)
		return (-1);
	return (0);
}

static int		read_loop(ssize_t ret, char *buf, int fd, t_tet **minos)
{
	ssize_t		end;
	char		*temp;

	end = -1;
	while (ret > 0)
	{
		ret = read(fd, buf, 21);
		if (ret == 20)
			end = 1;
		if (ret == 0 && ft_strlen(buf) != 0 && end == 1)
			return (0);
		buf[ret] = '\0';
		temp = ft_strdup(buf);
		if (temp == NULL)
			return (-1);
		if (ft_lst_creator(temp, minos) == -1)
			return (-1);
		ft_strclr(temp);
	}
	return (-1);
}

int				save_valid(const char *file, t_tet **minos)
{
	int		fd;
	ssize_t	ret;
	char	buf[21];

	ret = 21;
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, buf, 0) != 0)
		return (-1);
	if (read_loop(ret, buf, fd, minos) == -1)
		return (-1);
	return (0);
}
