/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:18 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/12 17:17:54 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_game *game, int new_x, int new_y)
{
	handle_direction(game, new_x, new_y);
	if (game->map[new_y][new_x] == '1'
	|| (game->map[new_y][new_x] == 'E' && game->collectibles != 0))
		return ;
	if (game->map[new_y][new_x] == 'C')
		game->collectibles--;
	if (game->collectibles == 0)
	{
		if (game->exit.img)
			mlx_destroy_image(game->mlx, game->exit.img);
		game->exit.img = mlx_xpm_file_to_image(game->mlx,
				"xpm/Exit/e_o.xpm", &game->exit.width, &game->exit.height);
	}
	if (game->map[new_y][new_x] == 'E' && game->collectibles == 0)
	{
		ft_putstr("you win\n");
		close_game(game);
	}
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[game->player_y][game->player_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

int	handle_input(int key, t_game *game)
{
	if (key == 65307)
		close_game(game);
	else if (key == 'r')
	{
		free_resources(game);
		ft_putstr("You reset the game good luck!\n\n");
		main(game->argc, game->argv);
	}
	else if ((key == 'w' || key == 65362) && game->player_y > 0)
		move_player(game, game->player_x, game->player_y - 1);
	else if ((key == 's' || key == 65364) && game->player_y < game->height - 1)
		move_player(game, game->player_x, game->player_y + 1);
	else if ((key == 'a' || key == 65361) && game->player_x > 0)
		move_player(game, game->player_x - 1, game->player_y);
	else if ((key == 'd' || key == 65363) && game->player_x < game->width - 1)
		move_player(game, game->player_x + 1, game->player_y);
	else
		return (0);
	if (check_collision(game))
		return (0);
	render_map(game);
	return (0);
}

void	free_resources(t_game *game)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->height)
			free(game->map[i]);
		free(game->map);
	}
	free_textures(game);
}

void	free_textures(t_game *game)
{
	if (game->wall.img)
		mlx_destroy_image(game->mlx, game->wall.img);
	if (game->collectible.img)
		mlx_destroy_image(game->mlx, game->collectible.img);
	if (game->exit.img)
		mlx_destroy_image(game->mlx, game->exit.img);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
	if (game->floor.img)
		mlx_destroy_image(game->mlx, game->floor.img);
	if (game->enemies)
		free_enemy(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	load_textures(t_game *game)
{
	game->wall.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/Tiles/block.xpm", &game->wall.width, &game->wall.height);
	game->collectible.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/Collectibles/star_00.xpm",
			&game->collectible.width, &game->collectible.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/Exit/exit_close_01.xpm",
			&game->exit.width, &game->exit.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/Player/idle_00.xpm", &game->player.width,
			&game->player.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx,
			"xpm/Tiles/midBlocks_02.xpm", &game->floor.width,
			&game->floor.height);
}
