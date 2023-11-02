/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gverissi <gverissi@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:35:43 by gverissi          #+#    #+#             */
/*   Updated: 2023/04/24 10:25:09 by gverissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, unsigned char ch)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ch == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) ch)
			return ((char *)&str[i]);
		i++;
	}
	return (0);
}
