/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:44:45 by qang              #+#    #+#             */
/*   Updated: 2023/05/17 16:48:28 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putui(unsigned int n, int *count)
{
	if (n > 9)
		ft_putui(n / 10, count);
	n = n % 10 + 48;
	s_putchar(n, count);
}
