/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:54:26 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/16 19:02:27 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	concat_len;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	while (dest_len < size && dest[dest_len] != '\0')
		dest_len++;
	if (dest_len == size)
		return (size + src_len);
	concat_len = size - dest_len - 1;
	while (i < concat_len && src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
