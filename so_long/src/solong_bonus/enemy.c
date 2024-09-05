/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:29:44 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/05 14:15:58 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// void	init_enemy(t_enemy *enemy)

void	add_enemy(t_enemy **enemies, int x, int y)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	enemy->x = x;
	enemy->y = y;
	enemy->next = NULL;
	if (!enemies || !*enemies)
	{
		*enemies = enemy;
		return ;
	}
	enemy->next = *enemies;
	*enemies = enemy;
	return ;
}

void	free_enemy(t_game *game)
{
	t_enemy		*enemies;
	t_enemy		*prev;

	enemies = game->enemies;
	while (enemies)
	{
		if (enemies->enemy.img)
			mlx_destroy_image(game->mlx, enemies->enemy.img);
		prev = enemies;
		enemies = enemies->next;
		free(prev);
	}
}

void	move_enemy(t_game *game)
{
	static unsigned int		seed = 123456789;
	t_enemy					*enemy;
	int						direction;

	if (!game->enemies)
		return ;
	enemy = game->enemies;
	while (enemy)
	{
		seed = (seed * 110245) % 263;
		direction = rand() % 4;
		if (direction == 0 && check_move(game, enemy->y - 1, enemy->x))
			game->map[enemy->y--][enemy->x] = '0';
		else if (direction == 1 && check_move(game, enemy->y + 1, enemy->x))
			game->map[enemy->y++][enemy->x] = '0';
		else if (direction == 2 && check_move(game, enemy->y, enemy->x - 1))
			game->map[enemy->y][enemy->x--] = '0';
		else if (direction == 3 && check_move(game, enemy->y, enemy->x + 1))
			game->map[enemy->y][enemy->x++] = '0';
		game->map[enemy->y][enemy->x] = 'T';
		enemy = enemy->next;
	}
}

int	check_collision(t_game *game)
{
	t_enemy		*enemy;

	enemy = game->enemies;
	while (enemy)
	{
		if (enemy->x == game->player_x && enemy->y == game->player_y)
		{
			ft_putstr("Game Over! You touched an enemy.\n");
			free_resources(game);
			exit(1);
		}
		enemy = enemy->next;
	}
	return (0);
}

int	check_move(t_game *game, int y, int x)
{
	return (game->map[y][x] == '0'
			|| game->map[y][x] == 'P');
}
