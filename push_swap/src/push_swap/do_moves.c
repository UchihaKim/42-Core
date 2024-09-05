/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:48:26 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:48:29 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rrr_move(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		(*cost_a)++;
		(*cost_b)++;
		rrr(a, b);
	}
}

void	do_rr_move(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		(*cost_a)--;
		(*cost_b)--;
		rr(a, b);
	}
}

void	do_ra_move(t_stack **a, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			rra(a);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			ra(a);
			(*cost)--;
		}
	}
}

void	do_rb_move(t_stack **b, int *cost)
{
	while (*cost)
	{
		if (*cost < 0)
		{
			rrb(b);
			(*cost)++;
		}
		else if (*cost > 0)
		{
			rb(b);
			(*cost)--;
		}
	}
}

void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		do_rrr_move(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		do_rr_move(a, b, &cost_a, &cost_b);
	do_ra_move(a, &cost_a);
	do_rb_move(b, &cost_b);
	pa(a, b);
}
