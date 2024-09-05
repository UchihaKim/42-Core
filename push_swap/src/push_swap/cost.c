/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:48:16 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:48:18 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_costs(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_b = *b;
	size_a = get_size(*a);
	size_b = get_size(*b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->cost_b > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->cost_a > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

void	do_cheapest_move(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b) < ft_abs(cheapest))
		{
			cheapest = ft_abs(tmp->cost_a) + ft_abs(tmp->cost_b);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	do_move(a, b, cost_a, cost_b);
}
