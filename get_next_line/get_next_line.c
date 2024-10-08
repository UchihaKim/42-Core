/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:20:18 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/20 17:07:33 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_line(char **remainder)
{
	char	*line;
	char	*new_remainder;
	ssize_t	len;

	len = -1;
	while (len++, len[(*remainder)] && len[(*remainder)] != '\n')
		;
	if ((*remainder)[len] == '\n')
	{
		line = (char *)malloc(len + 2);
		if (!line)
			return (NULL);
		line[++len] = '\0';
		while (len--, len >= 0)
			line[len] = len[(*remainder)];
		new_remainder = ft_strdup(*remainder + ft_strlen(line));
	}
	else
	{
		line = ft_strdup(*remainder);
		new_remainder = NULL;
	}
	free(*remainder);
	*remainder = new_remainder;
	return (line);
}

static int	read_to_remainder(int fd, char **remainder)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes_read;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
		return (free(buffer), bytes_read);
	buffer[bytes_read] = '\0';
	if (*remainder == NULL)
		*remainder = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(*remainder, buffer);
		free(*remainder);
		*remainder = tmp;
	}
	return (free(buffer), bytes_read);
}

char	*get_next_line(int fd)
{
	static char		*remainder = NULL;
	char			*line;
	int				bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	while (!ft_strchr(remainder, '\n'))
	{
		bytes_read = read_to_remainder(fd, &remainder);
		if ((bytes_read < 0) || (bytes_read == 0 && !*remainder))
		{
			free(remainder);
			remainder = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
	}
	line = get_line(&remainder);
	return (line);
}
