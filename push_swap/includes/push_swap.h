/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 17:32:15 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/11 17:32:19 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				index;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

void	push_value(t_stack **s, int value);
void	free_stack(t_stack *s);
void	sa(t_stack **s);
void	sb(t_stack **s);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **s);
void	rb(t_stack **s);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **s);
void	rrb(t_stack **s);
void	rrr(t_stack **a, t_stack **b);
int		is_sorted(t_stack *s);
int		get_lowest_index_position(t_stack **stack);
t_stack	*get_last_node(t_stack *s);
t_stack	*get_before_last_node(t_stack *s);
int		get_size(t_stack *s);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
int		ft_abs(int n);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t destsize);
char	**ft_split(const char *str, char c);
void	ft_free_split(char **split);
int		is_numeric(const char *str);
int		check_long_numbers(int argc, char **argv, int start_index);
long	*get_values_array(int argc, char **argv, int start_index);
int		is_duplicated(long nb, int argc, char **argv, int start_index);
int		check_one_arg_case(char **argv);
int		check_args(int argc, char **argv);
void	ft_putendl_fd(const char *str, int fd);
void	fill_stack(t_stack **s, int argc, char **argv);
void	fill_stack_one_arg(t_stack **a, char **argv);
void	push_until_three(t_stack **a, t_stack **b);
void	sort_three(t_stack **s);
void	assign_positions(t_stack **stack);
void	assign_target_positions(t_stack **a, t_stack **b);
void	do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void	assign_costs(t_stack **a, t_stack **b);
void	do_cheapest_move(t_stack **a, t_stack **b);
void	shift_stack(t_stack **s);
void	sort(t_stack **a, t_stack **b);

#endif
