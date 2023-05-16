/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:59:29 by qang              #+#    #+#             */
/*   Updated: 2023/05/16 10:59:43 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, int *count, int c)
{
	char	*base1;
	char	*base2;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	if (n > 15)
		ft_puthex(n / 16, count, c);
	n = n % 16;
	if (c == 'x')
		s_putchar(base1[n], count);
	else
		s_putchar(base2[n], count);
}
