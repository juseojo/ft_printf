/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:57 by seongjch          #+#    #+#             */
/*   Updated: 2022/03/25 22:18:45 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int type_checker(char type, va_list *valuse);

int ft_printf(const char *format, ...)
{
	int i;
	char *str;
	va_list values;

	i = 0;
	str = "";
	va_start(values, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			type_checker(format[++i], &values);
		}
		else 
			write(0, &format[i], 1);
		i++;
	}
	return (ft_strlen(format));
}

static int type_checker(char type, va_list *values)
{
	int temp;

	if (type == 'c')
		ft_putchar_fd(va_arg(*values, int), 0);
	else if (type == 's')
		ft_putstr_fd(va_arg(*values, char*), 0);
	else if (type == 'd' || type == 'i')
		ft_putnbr_fd(va_arg(*values, int), 0);
	else if (type == 'u')
	{
		temp = va_arg(*values, int);
		if (temp < 0)
			temp = -temp;
		ft_putnbr_fd(temp, 0);
	}
	else if (type == 'x')
		ft_puthexlow_fd(va_arg(*values, long long), 0);
	else if (type == 'X')
		ft_puthexup_fd(va_arg(*values, long long), 0);
	else if (type == 'p')
	{
		write(0,"0x",2);
		ft_putpoint_fd(va_arg(*values, long long), 0);
	}
	else if (type == '%')
		write(0, "%", 1);
	else
		return (-1);
	return (0);
}
