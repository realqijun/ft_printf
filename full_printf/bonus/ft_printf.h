/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 17:15:53 by qang              #+#    #+#             */
/*   Updated: 2023/05/17 16:46:22 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int		justify;
	int		sign;
	int		base;
	int		space;
	int		pad;
	int		precision;
	size_t	width;
	size_t	prec;
}	t_list;

void	s_putchar(int c, int *count);
void	s_putstr(char *str, int *count, t_list *flags);
int		ft_printf(const char *s, ...);
void	s_putaddr(uintptr_t addy, int *count, t_list *flags);
/*ft_putnbrs.c & ft_putnbrs2.c*/
void	s_putnbr(int n, int *count, t_list *flags);
void	s_putnbr2(int n, int *count, t_list *flags, size_t len);
void	s_putnbr3(int n, int *count, t_list *flags, size_t len);
void	s_putnbr4(int n, int *count, t_list *flags, size_t len);
void	s_putnbr5(int n, int *count, t_list *flags, size_t len);
void	s_putnbr6(int n, int *count, t_list *flags, size_t len);
void	s_putnbr7(int n, int *count, t_list *flags, size_t len);
size_t	digits(int n);
void	ft_putnbr(int n, int *count);
void	ft_putsign(int n, int *count, t_list *flags);

/*ft_putui.c*/
void	s_putui(unsigned int n, int *count, t_list *flags);
void	ft_putui(unsigned int, int *count);

/*ft_puthex.c & ft_puthex2.c*/
void	s_puthex(unsigned int n, int *count, t_list *flags, int c);
void	s_puthex2(unsigned int n, int *count, t_list *flags, int c);
void	s_puthex3(unsigned int n, int *count, t_list *flags, int c);
void	s_puthex4(unsigned int n, int *count, t_list *flags, int c);
void	s_puthex5(unsigned int n, int *count, t_list *flags, int c);
void	s_puthex6(unsigned int n, int *count, t_list *flags, int c);
void	s_puthex7(unsigned int n, int *count, t_list *flags, int c);
void	ft_puthex(unsigned int n, int *count, int c);
size_t	hdigits(unsigned int n);
void	writebase(int *count, t_list *flags, int c);

void	ss_putchar(int c, int *count, t_list *flags);

#endif
