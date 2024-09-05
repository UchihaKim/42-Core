/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:21:53 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/12 14:53:58 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t				s_len;
	size_t				c_len;
	char				*d;
	const char			*s;

	s_len = ft_strlen(src);
	if (dstsize > 0)
	{
		if (s_len >= dstsize)
			c_len = dstsize - 1;
		else
			c_len = s_len;
		d = dst;
		s = src;
		while (c_len--)
			*d++ = *s++;
		*d = '\0';
	}
	return (s_len);
}
