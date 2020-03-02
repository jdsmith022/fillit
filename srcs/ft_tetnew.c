/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tetnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 16:44:47 by mminkjan       #+#    #+#                */
/*   Updated: 2020/03/02 13:42:36 by jesmith       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	ft_tetback(t_tet **alst, t_tet *blst)
{
	t_tet	*temp;

	temp = *alst;
	if (temp == NULL)
	{
		*alst = blst;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = blst;
}

t_tet	*ft_tetnew(void const *content, size_t content_size, size_t sign)
{
	t_tet			*tet;

	tet = (t_tet*)malloc(sizeof(t_tet));
	if (!tet)
		return (NULL);
	if (content == NULL)
	{
		content_size = 0;
		tet->content = NULL;
		tet->next = NULL;
	}
	else
	{
		tet->content = (void*)malloc(content_size);
		if (!tet->content)
		{
			free(tet->content);
			return (0);
		}
		tet->content = ft_memcpy((tet->content), content, content_size);
		tet->content_size = sign;
	}
	tet->next = NULL;
	return (tet);
}
