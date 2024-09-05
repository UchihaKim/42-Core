/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:55 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:49:56 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_new_node(int value)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->pos = -1;
	new_node->target_pos = -1;
	new_node->cost_a = -1;
	new_node->cost_b = -1;
	new_node->next = NULL;
	return (new_node);
}

void	push_value(t_stack **s, int value)
{
	t_stack	*new_node;

	new_node = create_new_node(value);
	if (!new_node)
		return ;
	new_node->next = *s;
	*s = new_node;
}

void	free_stack(t_stack *s)
{
	t_stack	*tmp;

	if (!s)
		return ;
	while (s)
	{
		tmp = s;
		s = s->next;
		free(tmp);
	}
}
