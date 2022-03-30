/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexup_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:51:24 by seongjch          #+#    #+#             */
/*   Updated: 2022/03/30 15:53:35 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexup_fd(long long ln, int fd)
{
	int cnt;

	cnt = 0;
	if (ln > 2147483647)
		ln %= 0x100000000;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
		cnt++;
	}
	if (ln >= 0x10)
	{
		cnt += ft_puthexup_fd(ln / 0x10, fd);
		ln %= 0x10;
	}	
	if (ln < 10)
		ft_putchar_fd(ln + '0', fd);
	else
		ft_putchar_fd((ln % 10) + 'A', fd);
	cnt++;
	return (cnt);
}
