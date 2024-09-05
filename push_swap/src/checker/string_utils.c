/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:47:51 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:47:52 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (destsize == 0)
		return (srclen);
	i = 0;
	while (i < destsize - 1 && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (i <= (int)ft_strlen(str))
	{
		if (str[i] == (unsigned char)c)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	char	*p;
	size_t	reslen;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < (size_t) start)
		return (ft_strdup(""));
	p = (char *)s + start;
	if (ft_strlen(p) < len)
		reslen = ft_strlen(p) + 1;
	else
		reslen = len + 1;
	new_str = (char *)malloc(reslen);
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, p, reslen);
	return (new_str);
}
