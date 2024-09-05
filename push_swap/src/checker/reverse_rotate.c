/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:35:30 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:35:38 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reverse_rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	if (!*s)
		return ;
	tmp = *s;
	tail = get_last_node(*s);
	before_tail = get_before_last_node(*s);
	*s = tail;
	(*s)->next = tmp;
	before_tail->next = NULL;
}

void	rra(t_stack **s)
{
	reverse_rotate(s);
}

void	rrb(t_stack **s)
{
	reverse_rotate(s);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
