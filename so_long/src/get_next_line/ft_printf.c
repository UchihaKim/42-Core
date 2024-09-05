/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 17:10:40 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/12 17:17:01 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdarg.h>

void	put_string(char *string, int *l)
{
	if (!string)
		string = "(null)";
	while (*string)
		*l += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *l)
{
	char	*hexadecimal;

	hexadecimal = "0123456789abcdef";
	if (number < 0)
	{
		number *= -1;
		*l += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, l);
	*l += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int		l;
	va_list	pointer;

	l = 0;
	va_start(pointer, format);
	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's')
				|| (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &l);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &l);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &l);
		}
		else
			l += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), l);
}
