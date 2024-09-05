/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:30 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:49:34 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **s)
{
	t_stack	*tmp;
	t_stack	*tail;

	if (!*s)
		return ;
	tmp = *s;
	tail = get_last_node(*s);
	(*s) = (*s)->next;
	tmp->next = NULL;
	tail->next = tmp;
}

void	ra(t_stack **s)
{
	rotate(s);
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **s)
{
	rotate(s);
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
}
