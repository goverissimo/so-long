/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:04:54 by gverissi          #+#    #+#             */
/*   Updated: 2023/12/04 14:52:18 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
int		ft_print_ptr(unsigned long ptr);
int		ft_putstr_fds(char *s, int fd);
int		ft_putnbr_fds(int n, int fd);
int		ft_putchar_fds(char c, int fd);
#endif