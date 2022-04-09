/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:51:24 by seongjch          #+#    #+#             */
/*   Updated: 2022/04/09 18:29:42 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpoint_fd(unsigned long long ln, int fd)
{
	int	cnt;

	cnt = 0;
	if (ln >= 0x10)
	{
		cnt += ft_putpoint_fd(ln / 0x10, fd);
		ln %= 0x10;
	}
	if (ln < 10)
	{
		if (ft_putchar_fd(ln + '0', fd) == -1)
			return (-1);
	}
	else
	{
		if (ft_putchar_fd((ln % 10) + 'a', fd) == -1)
			return (-1);
	}
	cnt++;
	return (cnt);
}
