/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:48:35 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:48:36 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	assign_indices(t_stack *s, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = s;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = s;
			}
			else
				ptr = ptr->next;
		}
		if (highest)
			highest->index = stack_size;
	}
}

void	fill_stack(t_stack **s, int argc, char **argv)
{
	int	stack_size;

	get_stack_values(s, argc, argv);
	stack_size = get_size(*s);
	assign_indices(*s, stack_size + 1);
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
	i = get_size(*a);
	assign_indices(*a, i + 1);
	ft_free_split(split);
}
