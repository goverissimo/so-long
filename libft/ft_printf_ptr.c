/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 15:04:29 by gverissi          #+#    #+#             */
/*   Updated: 2023/11/27 16:26:02 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int	ft_write_ptr(unsigned long ptr)
{
	int	index;
	int	c;

	c = 0;
	index = 0;
	if (ptr >= 16)
	{
		c += ft_write_ptr(ptr / 16);
		c += ft_write_ptr(ptr % 16);
	}
	else
	{
		index = ptr % 16;
		ft_putchar_fds(HEX_L[index], 1);
		c++;
	}
	return (c);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	print_len;

	print_len = 0;
	if (ptr == 0)
		return (ft_putstr_fds("(nil)", 1));
	else
	{
		print_len += ft_putstr_fds("0x", 1);
		print_len += ft_write_ptr(ptr);
	}
	return (print_len);
}