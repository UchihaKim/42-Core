/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:49:14 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:49:19 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putendl_fd("pb", 1);
}
