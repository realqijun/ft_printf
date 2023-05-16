/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:45:23 by qang              #+#    #+#             */
/*   Updated: 2023/05/16 11:54:58 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ss_putchar(int c, int *count, t_list *flags)
{
	if (flags->width > 1)
	{
		if (flags->justify)
		{
			s_putchar(c, count);
			while ((flags->width)-- > 1)
				s_putchar(' ', count);
		}
		else
		{
			while ((flags->width)-- > 1)
				s_putchar(' ', count);
			s_putchar(c, count);
		}
	}
	else
		s_putchar(c, count);
}

void	s_putchar(int c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static void	s_putstr2(char *str, int *count, t_list *flags, size_t len)
{
	if (!(flags->precision))
	{
		if (!(flags->justify))
			while ((flags->width)-- > len)
				s_putchar(' ', count);
		while (*str)
			s_putchar(*str++, count);
		if (flags->justify)
			while ((flags->width)-- > len)
				s_putchar(' ', count);
	}
	else
		while (*str)
			s_putchar(*str++, count);
}

void	s_putstr(char *str, int *count, t_list *flags)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->width <= len)
	{
		if (!(flags->precision))
			while (*str)
				s_putchar(*str++, count);
		else
			while ((flags->width)--)
				s_putchar(*str++, count);
	}
	else
		s_putstr2(str, count, flags, len);
}
