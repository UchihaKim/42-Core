/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:10:33 by kabbas            #+#    #+#             */
/*   Updated: 2024/06/16 14:37:05 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

int	word_count(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (!s || !*s)
		return (counter);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		counter++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (counter);
}

char	*helper(const char *s, int start, char c)
{
	int		i;
	int		j;
	char	*word;

	i = 0;
	while (s[i + start] && s[i + start] != c)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < i)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(const char *s, char c)
{
	int		i;
	int		j;
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		res[j] = helper(s, i, c);
		j++;
		while (s[i] && s[i] != c)
			i++;
	}
	res[j] = NULL;
	return (res);
}
