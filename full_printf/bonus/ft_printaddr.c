/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:14:47 by qang              #+#    #+#             */
/*   Updated: 2023/05/16 12:00:33 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	r_addy(uintptr_t addy, int *count, char *base)
{
	if (addy > 15)
		r_addy(addy / 16, count, base);
	addy %= 16;
	write(1, &base[addy], 1);
	*count += 1;
}

static size_t	len(uintptr_t addy)
{
	size_t	i;

	i = 0;
	if (addy == 0)
		return (1);
	while (addy > 0)
	{
		addy /= 16;
		i++;
	}
	return (i);
}

void	s_putaddr(uintptr_t addy, int *count, t_list *flags)
{
	char		*base;
	size_t		i;

	i = len(addy);
	if (flags->width > i + 2 && !(flags->justify))
		while ((flags->width)-- > i + 2)
			s_putchar(' ', count);
	base = "0123456789abcdef";
	*count += write(1, "0x", 2);
	r_addy(addy, count, base);
	if (flags->width > i + 2 && flags->justify)
		while ((flags->width)-- > i + 2)
			s_putchar(' ', count);
}
