/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:51:24 by seongjch          #+#    #+#             */
/*   Updated: 2022/03/30 17:00:52 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putpoint_fd(unsigned long ln, int fd)
{
	int cnt;

	cnt = 0;
	if (ln >= 0x10)
	{
		cnt += ft_putpoint_fd(ln / 0x10, fd);
		ln %= 0x10;
	}
	if (ln < 10)
		ft_putchar_fd(ln + '0', fd);
	else
		ft_putchar_fd((ln % 10) + 'a', fd);
	cnt++;
	return (cnt);
}
