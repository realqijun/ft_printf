/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:00:19 by qang              #+#    #+#             */
/*   Updated: 2023/05/16 11:00:30 by qang             ###   ########.fr       */
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
		n /= 16;
		i++;
	}
	return (i);
}

static void	writebase(int *count, size_t *len, t_list *flags, int c)
{
	if (flags->base)
	{
		if (c == 'x')
		{
			*count += write(1, "0x", 2);
			*len += 2;
		}
		else
		{
			*count += write(1, "0X", 2);
			*len += 2;
		}
	}
	if (flags->base && flags->precision)
		*len -= 2;
}

static void	s_puthex3(unsigned int n, int *count, t_list *flags, int c)
{
	size_t	len;

	len = digit(n);
	writebase(count, &len, flags, c);
	ft_puthex(n, count, c);
	if (flags->precision || flags->pad)
		while ((flags->width)-- > len)
			s_putchar('0', count);
	else
		while ((flags->width)-- > len)
			s_putchar(' ', count);
}

static void	s_puthex2(unsigned int n, int *count, t_list *flags, int c)
{
	size_t	len;

	len = digit(n);
	if (flags->precision || flags->pad)
	{
		writebase(count, &len, flags, c);
		while ((flags->width)-- > len)
			s_putchar('0', count);
		ft_puthex(n, count, c);
	}
	else
	{			
		if (flags->base)
			len += 2;
		while ((flags->width)-- > len)
			s_putchar(' ', count);
		writebase(count, &len, flags, c);
		ft_puthex(n, count, c);
	}
}

void	s_puthex(unsigned int n, int *count, t_list *flags, int c)
{
	size_t	len;

	len = digit(n);
	if (flags->width > len)
	{
		if (flags->justify)
			s_puthex3(n, count, flags, c);
		else
			s_puthex2(n, count, flags, c);
	}
	else
	{
		if (n != 0)
			writebase(count, &len, flags, c);
		ft_puthex(n, count, c);
	}
}
