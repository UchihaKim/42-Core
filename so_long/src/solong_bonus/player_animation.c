/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 15:45:30 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/05 13:56:37 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_anim_player_down(t_game *game)
{
	static const char	*paths[3] = {
		"xpm/Player/walkDown_00.xpm",
		"xpm/Player/walkDown_01.xpm",
		"xpm/Player/walkDown_02.xpm"
	};

	if (game->anim_player >= 3)
		game->anim_player = 0;
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			(char*)paths[game->anim_player],
			&game->player.width,
			&game->player.height);
	game->anim_player++;
	return (0);
}

int	ft_anim_player_up(t_game *game)
{
	static const char	*paths[3] = {
		"xpm/Player/walkUP_00.xpm",
		"xpm/Player/walkUP_01.xpm",
		"xpm/Player/walkUP_02.xpm"
	};

	if (game->anim_player >= 3)
		game->anim_player = 0;
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			(char*)paths[game->anim_player],
			&game->player.width,
			&game->player.height);
	game->anim_player++;
	return (0);
}

int	ft_anim_player_right(t_game *game)
{
	static const char	*paths[3] = {
		"xpm/Player/walkRight_00.xpm",
		"xpm/Player/walkRight_01.xpm",
		"xpm/Player/walkRight_02.xpm"
	};

	if (game->anim_player >= 3)
		game->anim_player = 0;
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			(char*)paths[game->anim_player],
			&game->player.width,
			&game->player.height);
	game->anim_player++;
	return (0);
}

int	ft_anim_player_left(t_game *game)
{
	static const char	*paths[3] = {
		"xpm/Player/walkLeft_00.xpm",
		"xpm/Player/walkLeft_01.xpm",
		"xpm/Player/walkLeft_02.xpm"
	};

	if (game->anim_player >= 3)
		game->anim_player = 0;
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			(char*)paths[game->anim_player],
			&game->player.width,
			&game->player.height);
	game->anim_player++;
	return (0);
}

int	ft_anim_player_idle(t_game *game)
{
	static const char	*paths[7] = {
		"xpm/Player/idle_00.xpm",
		"xpm/Player/idle_01.xpm",
		"xpm/Player/idle_02.xpm",
		"xpm/Player/idle_03.xpm",
		"xpm/Player/idle_04.xpm",
		"xpm/Player/idle_05.xpm",
		"xpm/Player/idle_06.xpm"
	};

	if (game->anim_player >= 7)
		game->anim_player = 0;
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			(char*)paths[game->anim_player],
			&game->player.width,
			&game->player.height);
	game->anim_player++;
	return (0);
}
