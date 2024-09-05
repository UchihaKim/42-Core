/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:39 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:49:41 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_highest_index(t_stack *s)
{
	t_stack	*tmp;
	int		highest;

	tmp = s;
	highest = s->index;
	while (tmp)
	{
		if (tmp->index > highest)
			highest = tmp->index;
		tmp = tmp->next;
	}
	return (highest);
}

void	sort_three(t_stack **s)
{
	int	highest;

	if (is_sorted(*s))
		return ;
	highest = find_highest_index(*s);
	if ((*s)->index == highest)
		ra(s);
	else if ((*s)->next->index == highest)
		rra(s);
	if ((*s)->index > (*s)->next->index)
		sa(s);
}
