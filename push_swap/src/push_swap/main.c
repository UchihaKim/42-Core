/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:00 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:49:04 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	push_swap(t_stack **a, t_stack **b)
{
	if (get_size(*a) == 2 && (*a)->value > (*a)->next->value)
		sa(a);
	else if (get_size(*a) == 3)
		sort_three(a);
	else if (get_size(*a) > 3 && !is_sorted(*a))
		sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!check_args(argc, argv))
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
	a = NULL;
	if (argc != 2)
		fill_stack(&a, argc, argv);
	else
		fill_stack_one_arg(&a, argv);
	b = NULL;
	push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	exit(EXIT_SUCCESS);
}
