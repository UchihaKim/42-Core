/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:31:46 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:31:50 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				value;
}	t_stack;

int		ft_isdigit(int c);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		is_numeric(const char *str);
int		check_long_numbers(int argc, char **argv, int start_index);
int		is_duplicated(long nb, int argc, char **argv, int start_index);
int		check_one_arg_case(char **argv);
int		check_args(int argc, char **argv);
void	ft_putendl_fd(const char *str, int fd);
void	push_value(t_stack **s, int value);
void	free_stack(t_stack *s);
int		is_sorted(t_stack *s);
t_stack	*get_last_node(t_stack *s);
t_stack	*get_before_last_node(t_stack *s);
int		get_size(t_stack *s);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	rra(t_stack **s);
void	rrb(t_stack **s);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **s);
void	rb(t_stack **s);
void	rr(t_stack **a, t_stack **b);
void	sa(t_stack **s);
void	sb(t_stack **s);
void	ss(t_stack **a, t_stack **b);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	**ft_split(const char *str, char c);
void	ft_free_split(char **split);
int		ft_strcmp(const char *s1, const char *s2);
void	do_moves(t_stack **a, t_stack **b);

#endif
