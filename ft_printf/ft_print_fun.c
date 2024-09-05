/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:15:21 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/24 13:15:26 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int		length;

	if (!str)
	{
		write (1, "(null)", 6);
		return (6);
	}
	length = ft_strlen(str);
	write (1, str, length);
	return (length);
}

int	ft_putnumb(int n)
{
	int		length;
	char	*s;

	s = ft_itoa(n);
	length = ft_putstr(s);
	free(s);
	return (length);
}
