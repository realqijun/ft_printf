/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:46:34 by qang              #+#    #+#             */
/*   Updated: 2023/05/11 19:22:55 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnum(int n)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	nb = nb % 10 + 48;
	write(1, &nb, 1);
}

int	ft_putnbr(int n)
{
	int				i;
	unsigned int	k;

	i = 0;
	ft_putnum(n);
	if (n < 0)
	{
		i++;
		k = -n;
	}
	else
		k = n;
	if (k == 0)
		return (1);
	while (k > 0)
	{
		k /= 10;
		i++;
	}
	return (i);
}
