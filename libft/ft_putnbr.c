/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mminkjan <mminkjan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 12:10:24 by mminkjan       #+#    #+#                */
/*   Updated: 2019/01/31 17:26:06 by mminkjan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	char	nb;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = (n * -1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	nb = ('0' + (n % 10));
	write(1, &nb, 1);
}