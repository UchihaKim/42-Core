/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 18:50:06 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/05 14:06:08 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	end_with(char *src, const char *temp)
{
	int		len;
	int		len2;

	if (!src)
		return (0);
	len2 = 0;
	len = 0;
	while (temp[len])
		len++;
	while (src[len2])
		len2++;
	len--;
	len2--;
	while (len >= 0)
	{
		if (temp[len] != src[len2])
			break ;
		len--;
		len2--;
	}
	return (len == -1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			d;

	i = 0;
	d = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return (1);
		i++;
	}
	if (s[i] == d)
	{
		return (1);
	}
	return (0);
}

size_t	get_len(int n)
{
	size_t	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	num;

	num = n;
	len = get_len(n);
	if (n < 0)
		num = -n;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = num % 10 + '0';
		num /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
