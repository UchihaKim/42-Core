/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:45:22 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/14 18:57:53 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > 2147483647 / size)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	return (ft_memset(ptr, 0, nmemb * size));
}
