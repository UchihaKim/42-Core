/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:47:58 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:48:00 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap(t_stack **s)
{
	int	tmp;

	if (!*s || !(*s)->next)
		return ;
	tmp = (*s)->value;
	(*s)->value = (*s)->next->value;
	(*s)->next->value = tmp;
}

void	sa(t_stack **s)
{
	swap(s);
}

void	sb(t_stack **s)
{
	swap(s);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
