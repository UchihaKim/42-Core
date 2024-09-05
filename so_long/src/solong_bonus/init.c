/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:34:36 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/05 14:42:36 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_game_helper(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->moves = 0;
	game->collectibles = 0;
	game->enemies = NULL;
	game->last_enemy_move_time = 0;
	while (++y, y < game->height)
	{
		x = -1;
		while (++x, x < game->width)
		{
			if (game->map[y][x] == 'T')
				add_enemy(&game->enemies, x, y);
			if (game->map[y][x] == 'C')
				game->collectibles++;
			if (game->map[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
			}
		}
	}
	shapes(game);
}

void	check_map(t_game *game, char *file)
{
	if (!check_characters(game))
	{
		ft_putstr("Error\nBoundary not 1 or having intruder character\n");
		free_map(game, -1, file);
	}
	else if (!check_required(game))
	{
		ft_putstr("Error\nThe map must contain 1 exit, at least 1 collectible, and 1 starting\
		 position to be valid\n");
		free_map(game, -1, file);
	}
	else if (!check_valid_map(game, file))
	{
		ft_putstr("Error\nno valid path\n");
		free_map(game, -1, file);
	}
}

void	init_game(t_game *game, char *file)
{
	map(game, file);
	check_map(game, file);
	free_map(game, 0, file);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr("Error\nFailed MLX initialize\n");
		free_map(game, -1, file);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * S,
			game->height * S, "so long");
	if (!game->win)
	{
		if (game->mlx)
		{
			mlx_destroy_display(game->mlx);
			free(game->mlx);
		}
		ft_putstr("Error\nFailed loading window\n");
		free_map(game, -1, file);
	}
	init_game_helper(game);
}

void	shapes(t_game *game)
{
	t_enemy	*enemies;

	enemies = game->enemies;
	load_textures(game);
	while (enemies != NULL)
	{
		enemies->enemy.img = mlx_xpm_file_to_image(game->mlx,
				"xpm/Enemy/enemy_00.xpm",
				&enemies->enemy.width, &enemies->enemy.height);
		enemies = enemies->next;
	}
	if (!game->wall.img || !game->collectible.img || !game->exit.img
		|| !game->player.img || !game->floor.img
		|| (game->enemies && !game->enemies->enemy.img))
	{
		ft_putstr("Error\n problem in loading textures\n");
		free_resources(game);
		exit(1);
	}
}

int	main(int argc, char **av)
{
	t_game	game;

	game = (t_game){0};
	if (argc != 2 || !end_with(av[1], ".ber"))
	{
		ft_putstr("Error\nUsage: ");
		ft_putstr(av[0]);
		ft_putstr(" <map_file.ber>\n");
		return (1);
	}
	game.argc = argc;
	game.argv = av;
	init_game(&game, av[1]);
	mlx_hook(game.win, 2, 1L << 0, handle_input, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	render_map(&game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
