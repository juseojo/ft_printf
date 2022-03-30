/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:58:57 by seongjch          #+#    #+#             */
/*   Updated: 2022/03/30 16:34:23 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_checker(char type, va_list *valuse_p);
static int	type_checker_2(char type, va_list values);

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	char	*str;
	va_list	values;

	i = 0;
	str = "";
	count = 0;
	va_start(values, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += type_checker(format[++i], &values);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	return (count);
}

static int	type_checker(char type, va_list *values_p)
{
	if (type == 'c')
	{
		ft_putchar_fd(va_arg(*values_p, int), 1);
		return (1);
	}
	else if (type == 's')
		return (ft_putstr_fd(va_arg(*values_p, char *), 1));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr_fd(va_arg(*values_p, int), 1));
	else if (type == 'u')
		return (ft_putnbr_fd(va_arg(*values_p, unsigned int), 1));
	else if (type == 'x' || type == 'X' || type == 'p' || type == '%')
		return (type_checker_2(type, *values_p));
	return (0);
}

static int	type_checker_2(char type, va_list values)
{
	if (type == 'x')
		return (ft_puthexlow_fd(va_arg(values, long long), 1));
	else if (type == 'X')
		return (ft_puthexup_fd(va_arg(values, long long), 1));
	else if (type == 'p')
	{
		write(1, "0x", 2);
		return (ft_putpoint_fd(va_arg(values, long long), 1) + 2);
	}
	else if (type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}
