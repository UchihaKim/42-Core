/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:35:18 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:35:19 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	get_stack_values(t_stack **s, int argc, char **argv)
{
	int	i;

	i = argc - 1;
	while (i > 0)
	{
		push_value(s, ft_atoi(argv[i]));
		i--;
	}
}

void	fill_stack_one_arg(t_stack **a, char **argv)
{
	char	**split;
	int		split_size;
	int		i;

	split = ft_split(argv[1], ' ');
	if (!split)
		return ;
	i = -1;
	split_size = 0;
	while (split[++i])
		++split_size;
	i = split_size - 1;
	while (i >= 0)
	{
		push_value(a, ft_atoi(split[i]));
		i--;
	}
	ft_free_split(split);
}

int	check_args(int argc, char **argv)
{
	int	i;

	if (argc == 1)
	{
		exit(EXIT_SUCCESS);
		return (1);
	}
	if (argc == 2)
		return (check_one_arg_case(argv));
	if (!check_long_numbers(argc, argv, 1))
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_numeric(argv[i])
			|| is_duplicated(ft_atol(argv[i]), argc - 1, argv, 1))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (!check_args(argc, argv))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	if (argc > 2)
		get_stack_values(&a, argc, argv);
	else
		fill_stack_one_arg(&a, argv);
	do_moves(&a, &b);
	if (is_sorted(a) && !b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_stack(a);
	free_stack(b);
	exit(EXIT_SUCCESS);
}
