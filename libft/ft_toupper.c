/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/22 20:52:53 by mminkjan       #+#    #+#                */
/*   Updated: 2019/02/04 22:43:41 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = (c - 32);
	return (c);
}
