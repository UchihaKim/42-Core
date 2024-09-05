/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:50:00 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:50:01 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *s)
{
	t_stack	*tmp;

	if (!s || (s && !s->next))
		return (1);
	tmp = s;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	assign_positions(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

t_stack	*get_last_node(t_stack *s)
{
	t_stack	*tmp;

	if (!s)
		return (NULL);
	tmp = s;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*get_before_last_node(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}

int	get_size(t_stack *s)
{
	int		size;
	t_stack	*tmp;

	if (!s)
		return (0);
	size = 0;
	tmp = s;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
