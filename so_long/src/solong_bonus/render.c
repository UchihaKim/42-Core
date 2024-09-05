/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:31:28 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/05 14:05:49 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_images(t_game *game, int y, int x)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->wall.img, x * S, y * S);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->collectible.img, x * S, y * S);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->exit.img, x * S, y * S);
	else if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.img, x * S, y * S);
	else if (game->map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->floor.img, x * S, y * S);
	else if (game->map[y][x] == 'T')
		mlx_put_image_to_window(game->mlx, game->win,
			game->enemies->enemy.img, x * S, y * S);
}

int	render_map(t_game *game)
{
	static int	moves = -1;
	int			y;
	int			x;
	char		*moves_str;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			render_images(game, y, x);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win, 25, 25, 0xFF0000, "Moves: ");
	moves_str = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 65, 25, 0x00FF00, moves_str);
	free(moves_str);
	moves++;
	return (0);
}

void	handle_direction(t_game *game, int new_x, int new_y)
{
	if (new_x > game->player_x)
		game->direction = RIGHT;
	if (new_x < game->player_x)
		game->direction = LEFT;
	if (new_y > game->player_y)
		game->direction = DOWN;
	if (new_y < game->player_y)
		game->direction = UP;
}

void	free_map(t_game *game, int x, char *file)
{
	int	i;

	i = -1;
	if (game->map)
	{
		while (++i < game->height)
			free(game->map[i]);
		free(game->map);
	}
	if (x == 0)
		map(game, file);
	if (x == -1)
		exit(1);
}
