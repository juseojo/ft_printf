/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpoint_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:51:24 by seongjch          #+#    #+#             */
/*   Updated: 2022/03/25 22:17:34 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpoint_fd(long long ln, int fd)
{
	if (ln >= 0x10)
	{
		ft_putpoint_fd(ln / 0x10, fd);
		ln %= 0x10;
	}
	if (ln < 10)
		ft_putchar_fd(ln + '0', fd);
	else
		ft_putchar_fd((ln % 10) + 'a', fd);
}
