/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:15:32 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/24 13:15:33 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg(va_list args, const char format)
{
	if (format == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_putpointer(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_putnumb(va_arg(args, int)));
	else if (format == 'u')
		return (ft_putunsigned(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_puthexadecimal(va_arg(args, unsigned int), format));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		a;
	int			length;

	if (!format)
		return (-1);
	a = 0;
	length = 0;
	va_start(args, format);
	while (format[a])
	{
		if (format[a] == '%')
		{
			length += ft_arg(args, format[a + 1]);
			a++;
		}
		else
			length += ft_putchar(format[a]);
		a++;
	}
	va_end(args);
	return (length);
}
