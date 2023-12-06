/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:16:44 by gverissi          #+#    #+#             */
/*   Updated: 2023/12/04 14:49:02 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fds(char *s, int fd)
{
	int	c;

	if (!s || fd < 0)
		return (ft_putstr_fds("(null)", fd));
	write(fd, s, ft_strlen(s));
	c = ft_strlen(s);
	return (c);
}

int	ft_putnbr_fds(int n, int fd)
{
	long long int	nb;
	int				c;

	c = 0;
	nb = n;
	if (nb < 0)
	{
		ft_putchar_fds('-', fd);
		nb = nb * -1;
		c++;
	}
	if (nb >= 10)
	{
		c += ft_putnbr_fds(nb / 10, fd);
		ft_putnbr_fds(nb % 10, fd);
		c++;
	}
	else
	{
		c += ft_putchar_fds(nb + '0', fd);
	}
	return (c);
}

int	ft_putchar_fds(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}
