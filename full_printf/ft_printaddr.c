/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qang <qang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:34:37 by qang              #+#    #+#             */
/*   Updated: 2023/05/12 17:45:37 by qang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putptr(uintptr_t ptr)
{
	if (ptr > 15)
		ft_putptr(ptr / 16);
	ptr = ptr % 16;
	if (ptr < 10)
	{
		ptr = ptr + 48;
		write(1, &ptr, 1);
	}
	else
	{
		ptr = ptr + 87;
		write(1, &ptr, 1);
	}
}

static int	ft_ptrlen(uintptr_t ptr)
{
	int	len;

	len = 0;
	while (ptr > 0)
	{
		ptr /= 16;
		len++;
	}
	return (len);
}

void	ft_printaddr(uintptr_t ptr, int *count)
{
	*count += write(1, "0x", 2);
	if (ptr == 0)
		*count += write(1, "0", 1);
	else
	{
		*count += ft_ptrlen(ptr);
		ft_putptr(ptr);
	}
}
