/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongjuncho <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:44:53 by seongjuncho       #+#    #+#             */
/*   Updated: 2022/04/09 00:58:57 by seongjuncho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long long n, int fd);
int		ft_puthexlow_fd(unsigned int ln, int fd);
int		ft_puthexup_fd(unsigned int ln, int fd);
int		ft_putpoint_fd(unsigned int ln, int fd);

#endif
