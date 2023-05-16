/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 16:52:02 by qang              #+#    #+#             */
/*   Updated: 2023/05/16 15:21:33 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <ctype.h>

static int	ft_isdigit(int c)
{
	return (('0' <= c && c <= '9'));
}

static const char	*check_flags(const char *s, t_list *flags)
{
	while (*s == '-' || *s == '+' || *s == '#'
		|| *s == ' ' || *s == '.' || *s == '0')
	{
		if (*s == '-')
			flags->justify = 1;
		if (*s == '+')
			flags->sign = 1;
		if (*s == '#')
			flags->base = 1;
		if (*s == ' ')
			flags->space = 1;
		if (*s == '0')
			flags->pad = 1;
		if (*s == '.')
			flags->precision = 1;
		s++;
	}
	while (ft_isdigit(*s))
		flags->width = (flags->width) * 10 + *(s++) - 48;
	if (*s == '.')
		while (ft_isdigit(*(++s)))
			flags->prec = (flags->prec) * 10 + *s - 48;
	return (s);
}

static void	flag_init(t_list *flags)
{
	flags->justify = 0;
	flags->sign = 0;
	flags->base = 0;
	flags->space = 0;
	flags->pad = 0;
	flags->precision = 0;
	flags->width = 0;
	flags->prec = 0;
}

static void	print_var(const char *s, va_list vars, int *count, t_list *flags)
{
	if (*s == 'c')
		ss_putchar(va_arg(vars, int), count, flags);
	else if (*s == 's')
		s_putstr(va_arg(vars, char *), count, flags);
	else if (*s == 'p')
		s_putaddr(va_arg(vars, uintptr_t), count, flags);
	else if (*s == 'd' || *s == 'i')
		s_putnbr(va_arg(vars, int), count, flags);
	else if (*s == 'u')
		s_putui(va_arg(vars, unsigned int), count, flags);
	else if (*s == 'x' || *s == 'X')
		s_puthex(va_arg(vars, unsigned int), count, flags, *s);
	else if (*s == '%')
		s_putchar('%', count);
}

int	ft_printf(const char *s, ...)
{
	va_list	vars;
	int		count;
	t_list	*flags;

	count = 0;
	va_start(vars, s);
	while (*s)
	{
		flags = (t_list *)malloc(sizeof(t_list));
		if (flags == NULL)
			return (0);
		flag_init(flags);
		if (*s == '%')
		{
			s++;
			s = check_flags(s, flags);
			print_var(s, vars, &count, flags);
		}
		else
			s_putchar(*s, &count);
		s++;
		free(flags);
	}
	va_end(vars);
	return (count);
}
