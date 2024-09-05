/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:48:09 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:48:11 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		if (!str[i])
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_long_numbers(int argc, char **argv, int start_index)
{
	long	nb;
	int		i;

	i = start_index;
	while (i < argc)
	{
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

long	*get_values_array(int argc, char **argv, int start_index)
{
	long	*arr;
	int		i;
	int		j;
	int		array_size;

	i = start_index;
	array_size = argc - start_index;
	arr = (long *)malloc(array_size * sizeof(long));
	if (!arr)
		return (NULL);
	j = 0;
	while (i < argc)
	{
		arr[j] = ft_atol(argv[i]);
		i++;
		j++;
	}
	return (arr);
}

int	is_duplicated(long nb, int argc, char **argv, int start_index)
{
	long	*arr;
	int		i;
	int		count;
	int		array_size;

	array_size = argc - start_index;
	arr = get_values_array(argc, argv, start_index);
	i = 0;
	count = 0;
	if (!arr)
		return (1);
	while (i < array_size)
	{
		if (nb == arr[i])
			count++;
		i++;
	}
	free(arr);
	if (count > 1)
		return (1);
	else
		return (0);
}

int	check_one_arg_case(char **argv)
{
	char	**split;
	int		i;
	int		split_size;

	split = ft_split(argv[1], ' ');
	if (!split)
		return (0);
	if (!*split)
		return (ft_free_split(split), 0);
	i = -1;
	split_size = 0;
	while (split[++i])
		split_size++;
	if (!check_long_numbers(split_size, split, 0))
		return (ft_free_split(split), 0);
	i = 0;
	while (split[i])
	{
		if (!is_numeric(split[i])
			|| is_duplicated(ft_atol(split[i]), split_size, split, 0))
			return (ft_free_split(split), 0);
		i++;
	}
	return (ft_free_split(split), 1);
}
