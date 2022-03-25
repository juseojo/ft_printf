/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:57 by seongjch          #+#    #+#             */
/*   Updated: 2022/03/25 19:24:59 by seongjch         ###   ########.fr       */
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
	if (type == 'c')
		ft_putchar_fd(va_arg(*values, int), 0);
	/*else if (type == 's')
	else if (type == 'p')
	else if (type == 'd')
	else if (type == 'i')
	else if (type == 'u')
	else if (type == 'x')
	else if (type == 'X')
	else if (type == '%')
	else
		return (-1)
		*/
	return (0);
}
