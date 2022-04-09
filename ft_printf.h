/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:27:15 by seongjch          #+#    #+#             */
/*   Updated: 2022/04/09 18:14:57 by seongjch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long long n, int fd);
int		ft_puthexlow_fd(unsigned int ln, int fd);
int		ft_puthexup_fd(unsigned int ln, int fd);
int		ft_putpoint_fd(unsigned int ln, int fd);

#endif
