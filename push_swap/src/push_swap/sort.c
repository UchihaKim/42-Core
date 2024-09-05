/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:46 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:49:50 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_until_three(t_stack **a, t_stack **b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_size(*a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*a)->index <= stack_size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

void	shift_stack(t_stack **s)
{
	int	s_size;
	int	lowest_pos;

	s_size = get_size(*s);
	lowest_pos = get_lowest_index_position(s);
	if (lowest_pos > s_size / 2)
	{
		while (lowest_pos < s_size)
		{
			rra(s);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(s);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **a, t_stack **b)
{
	push_until_three(a, b);
	sort_three(a);
	while (*b)
	{
		assign_target_positions(a, b);
		assign_costs(a, b);
		do_cheapest_move(a, b);
	}
	if (!is_sorted(*a))
		shift_stack(a);
}
