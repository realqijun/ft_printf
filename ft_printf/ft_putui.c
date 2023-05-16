/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:43:03 by qang              #+#    #+#             */
/*   Updated: 2023/05/16 12:13:11 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digit(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_putui(unsigned int n, int *count)
{
	if (n > 9)
		ft_putui(n / 10, count);
	n = n % 10 + 48;
	s_putchar(n, count);
}

static void	s_putui2(unsigned int n, int *count, t_list *flags, size_t len)
{
	if (flags->pad || flags->precision)
	{
		while ((flags->width)-- > len)
			s_putchar('0', count);
		ft_putui(n, count);
	}
	else if (flags->justify)
	{
		ft_putui(n, count);
		while ((flags->width)-- > len)
			s_putchar(' ', count);
	}
	else
	{
		while ((flags->width)-- > len)
			s_putchar(' ', count);
		ft_putui(n, count);
	}
}

void	s_putui(unsigned int n, int *count, t_list *flags)
{
	size_t	len;

	len = digit(n);
	if (flags->width > len)
		s_putui2(n, count, flags, len);
	else
	{
		if (flags->precision && n == 0)
			return ;
		ft_putui(n, count);
	}
}
