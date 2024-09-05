/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 18:07:02 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/05 14:17:09 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_time_in_milliseconds(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_anim_collectible(t_game *game)
{
	static const char	*paths[3] = {
		"xpm/Collectibles/star_00.xpm",
		"xpm/Collectibles/star_01.xpm",
		"xpm/Collectibles/star_02.xpm"
	};

	if (game->anim_collectible >= 3)
		game->anim_collectible = 0;
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			(char*)paths[game->anim_collectible],
			&game->collectible.width,
			&game->collectible.height);
	game->anim_collectible++;
	return (0);
}

void	ft_anim_player(t_game *game)
{
	int			idle_time;
	static int	stable_time = 0;
	static int	last_moves = 0;

	idle_time = get_time_in_milliseconds();
	if (game->moves != last_moves)
	{
		stable_time = idle_time;
		last_moves = game->moves;
	}
	if (idle_time - stable_time > 2000)
	{
		ft_anim_player_idle(game);
		game->direction = IDLE;
	}
	else if (game->direction == UP)
		ft_anim_player_up(game);
	else if (game->direction == DOWN)
		ft_anim_player_down(game);
	else if (game->direction == LEFT)
		ft_anim_player_left(game);
	else if (game->direction == RIGHT)
		ft_anim_player_right(game);
}

int	ft_anim_enemy(t_game *game)
{
	static const char	*paths[3] = {
		"xpm/Enemy/enemy_00.xpm",
		"xpm/Enemy/enemy_01.xpm",
		"xpm/Enemy/enemy_02.xpm"
	};

	if (game->anim_enemy >= 3)
		game->anim_enemy = 0;
	if (game->enemies->enemy.img)
		mlx_destroy_image(game->mlx, game->enemies->enemy.img);
	game->enemies->enemy.img = mlx_xpm_file_to_image(game->mlx,
			(char*)paths[game->anim_enemy],
			&game->enemies->enemy.width,
			&game->enemies->enemy.height);
	game->anim_enemy++;
	return (0);
}

int	game_loop(t_game *game)
	{
	static int		last_update_time = 0;
	static int		last_move = 0;
	int				current_time;

	current_time = get_time_in_milliseconds();
	if (current_time - last_update_time > 100)
	{
		ft_anim_collectible(game);
		ft_anim_player(game);
		if (game->enemies)
			ft_anim_enemy(game);
		last_update_time = current_time;
	}
	if (current_time - last_move >= 500)
	{
		move_enemy(game);
		last_move = current_time;
		if (check_collision(game))
			return (0);
	}
	render_map(game);
	return (0);
}
