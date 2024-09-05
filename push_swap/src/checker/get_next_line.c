/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:35:08 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:35:14 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*get_before_newline(const char *str)
{
	char		*res;
	size_t		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_after_newline(const char *str)
{
	char		*res;
	size_t		i;
	size_t		j;

	j = ft_strlen(str);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] && str[i] == '\n')
		i++;
	res = (char *)malloc((j - i) + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		res[j] = str[i + j];
		j++;
	}
	res[j] = '\0';
	return (res);
}

void	ft_read_line(int fd, char **keep, char **tmp)
{
	char	*buf;
	int		r;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	r = 1;
	while (r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
		{
			ft_free_strings(&buf, keep, tmp);
			return ;
		}
		buf[r] = '\0';
		*tmp = ft_strdup(*keep);
		ft_free_strings(keep, NULL, NULL);
		*keep = ft_strjoin(*tmp, buf);
		ft_free_strings(tmp, NULL, NULL);
		if (ft_contains_newline(*keep))
			break ;
	}
	ft_free_strings(&buf, NULL, NULL);
}

char	*ft_parse_line(char **keep, char **tmp)
{
	char	*line;

	*tmp = ft_strdup(*keep);
	ft_free_strings(keep, NULL, NULL);
	*keep = get_after_newline(*tmp);
	line = get_before_newline(*tmp);
	ft_free_strings(tmp, NULL, NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*keep = NULL;
	char		*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = NULL;
	line = NULL;
	ft_read_line(fd, &keep, &tmp);
	if (keep && *keep)
		line = ft_parse_line(&keep, &tmp);
	if (!line || *line == '\0')
	{
		ft_free_strings(&line, &keep, &tmp);
		return (NULL);
	}
	return (line);
}
