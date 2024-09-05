/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:50:18 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:50:19 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	int	tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = (*s)->value;
	(*s)->value = (*s)->next->value;
	(*s)->next->value = tmp;
	tmp = (*s)->index;
	(*s)->index = (*s)->next->index;
	(*s)->next->index = tmp;
}

void	sa(t_stack **s)
{
	swap(s);
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **s)
{
	swap(s);
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
}
