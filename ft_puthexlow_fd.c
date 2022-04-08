/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexlow_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:51:24 by seongjch          #+#    #+#             */
/*   Updated: 2022/04/09 01:01:10 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexlow_fd(unsigned int ln, int fd)
{
	int	cnt;

	cnt = 0;
	if (ln > 2147483647)
		ln %= 0x100000000;
	if (ln >= 0x10)
	{
		cnt += ft_puthexlow_fd(ln / 0x10, fd);
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
