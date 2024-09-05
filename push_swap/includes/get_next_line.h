/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:32:01 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:32:04 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif

int			ft_contains_newline(const char *str);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *str);
char		*ft_strjoin(const char *s1, const char *s2);
void		ft_free_strings(char **s1, char **s2, char **s3);
char		*get_before_newline(const char *str);
char		*get_after_newline(const char *str);
void		ft_read_line(int fd, char **keep, char **tmp);
char		*ft_parse_line(char **keep, char **tmp);
char		*get_next_line(int fd);

#endif
