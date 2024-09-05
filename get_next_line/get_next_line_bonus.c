/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:11:17 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/20 18:30:33 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*get_line(char **remainder)
{
	char	*line;
	char	*new_remainder;
	ssize_t	len;

	len = 0;
	while ((*remainder)[len] && (*remainder)[len] != '\n')
		len++;
	if ((*remainder)[len] == '\n')
	{
		line = (char *)malloc(len + 2);
		if (!line)
			return (NULL);
		line[++len] = '\0';
		while (len--, len >= 0)
			line[len] = (*remainder)[len];
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
	{
		free(buffer);
		return (bytes_read);
	}
	buffer[bytes_read] = '\0';
	if (*remainder == NULL)
		*remainder = ft_strdup(buffer);
	else
	{
		tmp = ft_strjoin(*remainder, buffer);
		free(*remainder);
		*remainder = tmp;
	}
	free(buffer);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static char	*remainders[MAX_FD] = {NULL};
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainders[fd])
		remainders[fd] = ft_strdup("");
	while (!ft_strchr(remainders[fd], '\n'))
	{
		bytes_read = read_to_remainder(fd, &remainders[fd]);
		if (bytes_read <= 0 && !*remainders[fd])
		{
			free(remainders[fd]);
			remainders[fd] = NULL;
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
	}
	line = get_line(&remainders[fd]);
	return (line);
}
