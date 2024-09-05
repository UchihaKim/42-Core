/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:15:51 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/24 13:15:52 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lengthnum(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		length++;
		num /= 10;
	}
	return (length);
}

char	*ft_utoa(unsigned int n)
{
	char	*convert;
	int		len;

	len = ft_lengthnum(n);
	convert = (char *)malloc((len + 1) * sizeof(char *));
	if (!convert)
		return (NULL);
	convert[len] = '\0';
	while (n != 0)
	{
		convert[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (convert);
}

int	ft_putunsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write (1, "0", 1);
	else
	{
		num = ft_utoa(n);
		len += ft_putstr(num);
		free(num);
	}
	return (len);
}
