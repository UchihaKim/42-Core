/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:34:33 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:34:38 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	is_a_move(const char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	if (ft_strcmp(str, "sb") == 0)
		return (1);
	if (ft_strcmp(str, "ss") == 0)
		return (1);
	if (ft_strcmp(str, "pa") == 0)
		return (1);
	if (ft_strcmp(str, "pb") == 0)
		return (1);
	if (ft_strcmp(str, "ra") == 0)
		return (1);
	if (ft_strcmp(str, "rb") == 0)
		return (1);
	if (ft_strcmp(str, "rr") == 0)
		return (1);
	if (ft_strcmp(str, "rra") == 0)
		return (1);
	if (ft_strcmp(str, "rrb") == 0)
		return (1);
	if (ft_strcmp(str, "rrr") == 0)
		return (1);
	return (0);
}

void	do_one_move(const char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa") == 0)
		sa(a);
	if (ft_strcmp(str, "sb") == 0)
		sb(b);
	if (ft_strcmp(str, "ss") == 0)
		ss(a, b);
	if (ft_strcmp(str, "pa") == 0)
		pa(a, b);
	if (ft_strcmp(str, "pb") == 0)
		pb(a, b);
	if (ft_strcmp(str, "ra") == 0)
		ra(a);
	if (ft_strcmp(str, "rb") == 0)
		rb(b);
	if (ft_strcmp(str, "rr") == 0)
		rr(a, b);
	if (ft_strcmp(str, "rra") == 0)
		rra(a);
	if (ft_strcmp(str, "rrb") == 0)
		rrb(b);
	if (ft_strcmp(str, "rrr") == 0)
		rrr(a, b);
}

void	handle_wrong_move_case(char *line, char *move, t_stack *a, t_stack *b)
{
	free(move);
	while (line)
	{
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free_stack(a);
	free_stack(b);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

void	do_moves(t_stack **a, t_stack **b)
{
	char	*line;
	char	*move;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strchr(line, '\n'))
			move = ft_substr(line, 0, ft_strlen(line) - 1);
		else
			move = ft_strdup(line);
		if (!is_a_move(move))
			handle_wrong_move_case(line, move, *a, *b);
		do_one_move(move, a, b);
		free(move);
		free(line);
		line = get_next_line(0);
	}
}
