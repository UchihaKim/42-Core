/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:15:41 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/24 13:15:43 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
int		ft_putnumb(int n);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_putpointer(unsigned long long ptr);
int		ft_puthexadecimal(unsigned int num, const char type);
int		ft_putunsigned(unsigned int n);
#endif
