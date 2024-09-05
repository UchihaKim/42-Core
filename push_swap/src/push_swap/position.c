/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:08 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:49:10 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_positions(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

void	get_target(t_stack **a, int b_idx,
					int target_idx, int *target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	*target_pos = 0;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			*target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return ;
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			*target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
}

void	assign_target_positions(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		target_pos;

	tmp = *b;
	assign_positions(a);
	assign_positions(b);
	while (tmp != NULL)
	{
		get_target(a, tmp->index, INT_MAX, &target_pos);
		tmp->target_pos = target_pos;
		tmp = tmp->next;
	}
}
