/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:44:37 by qang              #+#    #+#             */
/*   Updated: 2023/05/12 17:44:30 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_write(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

static void	ft_flag(va_list vars, int *count, const char *s)
{
	if (*s == 'c')
		*count += ft_putchar(va_arg(vars, int));
	else if (*s == 's')
		*count += ft_putstr(va_arg(vars, char *));
	else if (*s == 'p')
		ft_printaddr(va_arg(vars, uintptr_t), count);
	else if (*s == 'd')
		*count += ft_putnbr(va_arg(vars, int));
	else if (*s == 'i')
		*count += ft_putnbr(va_arg(vars, int));
	else if (*s == 'u')
		*count += ft_putui(va_arg(vars, unsigned int));
	else if (*s == 'x')
		*count += ft_puthex(va_arg(vars, int));
	else if (*s == 'X')
		*count += ft_bighex(va_arg(vars, int));
	else if (*s == '%')
		*count += ft_putchar('%');
}

int	ft_printf(const char *s, ...)
{
	va_list	vars;
	int		count;

	count = 0;
	va_start(vars, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_flag(vars, &count, s);
		}
		else
			ft_write(*s, &count);
		s++;
	}
	va_end(vars);
	return (count);
}
