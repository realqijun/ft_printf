/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:45:16 by qang              #+#    #+#             */
/*   Updated: 2023/05/11 19:24:20 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	hex(unsigned int i)
{
	char	*base;

	base = "0123456789abcdef";
	if (i > 15)
		hex(i / 16);
	i = i % 16;
	write(1, &base[i], 1);
}

int	ft_puthex(unsigned int n)
{
	int	i;

	i = 0;
	hex(n);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static void	bighex(unsigned int i)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (i > 15)
		bighex(i / 16);
	i = i % 16;
	write(1, &base[i], 1);
}

int	ft_bighex(unsigned int n)
{
	int	i;

	i = 0;
	bighex(n);
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}
