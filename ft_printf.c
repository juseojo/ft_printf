/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:57 by seongjch          #+#    #+#             */
/*   Updated: 2022/03/25 16:22:06 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *format, ...)
{
	int i;
	char *str;
	va_list values;

	i = 0;
	str = "";
	ft_strlcat(str, format, ft_strlen(format));
	va_start(values, format);
	while (!str[i])
	{
		if (str[i] == '%')
		{
			i++;
		}
		else 
			write(1, &str[i], 1);
		i++;
	}
	return (0);
}

int main()
{
	ft_printf("yap");
}
