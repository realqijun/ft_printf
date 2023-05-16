/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:14:14 by qang              #+#    #+#             */
/*   Updated: 2023/05/16 11:01:56 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	digits(int n)
{
	unsigned int	nb;
	size_t			i;

	i = 0;
	if (n < 0)
		nb = -n;
	else
		nb = n;
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	if (n == 0)
		return (1);
	return (i);
}

static void	ft_putnbr(int n, int *count)
{
	unsigned int	nb;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	if (nb > 9)
		ft_putnbr(nb / 10, count);
	nb = nb % 10 + 48;
	s_putchar(nb, count);
}

static void	ft_putsign(int n, int *count, t_list *flags)
{
	if (flags->space)
	{
		if (n >= 0)
			s_putchar(' ', count);
		else
			s_putchar('-', count);
	}
	else if (flags->sign)
	{
		if (n >= 0)
			s_putchar('+', count);
		else
			s_putchar('-', count);
	}
	else if (n < 0)
		s_putchar('-', count);
}

static void	s_putnbr2(int n, int *count, t_list *flags, size_t len)
{
	if (flags->pad || flags->precision)
	{
		ft_putsign(n, count, flags);
		while ((flags->width)-- > len)
			s_putchar('0', count);
		ft_putnbr(n, count);
	}
	else if (flags->justify)
	{
		ft_putsign(n, count, flags);
		ft_putnbr(n, count);
		while ((flags->width)-- > len)
			s_putchar(' ', count);
	}			
	else
	{
		while ((flags->width)-- > len)
			s_putchar(' ', count);
		ft_putsign(n, count, flags);
		ft_putnbr(n, count);
	}
}

void	s_putnbr(int n, int *count, t_list *flags)
{
	size_t	len;

	len = digits(n);
	if (flags->space || flags->sign || n < 0)
		len++;
	if (flags->precision && n < 0)
		len--;
	if (flags->width > len)
		s_putnbr2(n, count, flags, len);
	else
	{
		ft_putsign(n, count, flags);
		ft_putnbr(n, count);
	}
}
