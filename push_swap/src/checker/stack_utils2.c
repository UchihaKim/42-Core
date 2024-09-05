/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:47:44 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:47:46 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
