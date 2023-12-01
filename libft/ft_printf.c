/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:04:47 by gverissi          #+#    #+#             */
/*   Updated: 2023/11/27 16:12:57 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int num, char format)
{
	int	c;

	c = 0;
	if (num == 0)
	{
		c += ft_putstr_fds("0", 1);
		return (c);
	}
	if (num >= 16)
		c += ft_print_hex(num / 16, format);
	if (format == 'x')
		ft_putchar_fds(HEX_L[num % 16], 1);
	else if (format == 'X')
		ft_putchar_fds(HEX_U[num % 16], 1);
	c++;
	return (c);
}

int	ft_print_unsigned(unsigned int nb, int fd)
{
	int	c;

	c = 0;
	if (nb < 10)
		c += ft_putchar_fds(nb + '0', fd);
	else
	{
		c += ft_print_unsigned(nb / 10, fd);
		c += ft_putchar_fds(nb % 10 + '0', fd);
	}
	return (c);
}

int	ft_is_format(va_list args, char next_c)
{
	int	print_len;

	print_len = 0;
	if (next_c == 'c')
		print_len += (int)ft_putchar_fds((char)va_arg(args, int), 1);
	else if (next_c == 's')
		print_len += ft_putstr_fds(va_arg(args, char *), 1);
	else if (next_c == 'i')
		print_len += ft_putnbr_fds(va_arg(args, int), 1);
	else if (next_c == 'u')
		print_len += ft_print_unsigned(va_arg(args, unsigned int), 1);
	else if (next_c == 'd')
		print_len += ft_putnbr_fds(va_arg(args, unsigned int), 1);
	else if (next_c == 'x')
		print_len += ft_print_hex(va_arg(args, unsigned long), 'x');
	else if (next_c == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned long), 'X');
	else if (next_c == '%')
		print_len += ft_putchar_fds('%', 1);
	else if (next_c == 'p')
		print_len += ft_print_ptr(va_arg(args, unsigned long));
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		print_len;
	int		c;
	va_list	args;

	print_len = 0;
	c = 0;
	va_start(args, str);
	while (str[c] != '\0')
	{
		if (str[c] == '%')
		{
			print_len += ft_is_format(args, str[c + 1]);
			c++;
		}
		else
		{
			write(1, &str[c], 1);
			print_len++;
		}
		c++;
	}
	va_end(args);
	return (print_len);
}