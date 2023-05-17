/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:36:27 by qang              #+#    #+#             */
/*   Updated: 2023/05/17 11:36:58 by qang             ###   ########.fr       */
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
