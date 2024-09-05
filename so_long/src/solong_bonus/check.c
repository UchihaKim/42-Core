/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:34:28 by kabbas            #+#    #+#             */
/*   Updated: 2024/07/31 16:35:36 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_characters(t_game *game)
{
	int		i;
	int		j;

	i = -1;
	while (++i < game->width)
		if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1')
			return (0);
	i = -1;
	while (++i < game->height)
		if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			return (0);
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'E'
				&& game->map[i][j] != 'P' && game->map[i][j] != 'T'
				&& game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
		}
	}
	return (1);
}

int	check_required(t_game *game)
{
	int		i;
	int		j;
	int		inputs[3];

	inputs[0] = 0;
	inputs[1] = 0;
	inputs[2] = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'C')
				inputs[0]++;
			else if (game->map[i][j] == 'E')
				inputs[1]++;
			else if (game->map[i][j] == 'P')
				inputs[2]++;
		}
	}
	if (!inputs[0] || inputs[1] != 1 || inputs[2] != 1)
		return (0);
	return (1);
}

int	valid_map_path(t_game *game, int w, int h, char c)
{
	int	up;
	int	down;
	int	left;
	int	right;

	if (game->map[h][w] == '1' || game->map[h][w] == 'T'
		|| (game->map[h][w] == 'E' && 'P' == c))
		return (0);
	if (game->map[h][w] == c)
		return (1);
	game->map[h][w] = '1';
	up = valid_map_path(game, w, h - 1, c);
	down = valid_map_path(game, w, h + 1, c);
	right = valid_map_path(game, w + 1, h, c);
	left = valid_map_path(game, w - 1, h, c);
	return (up || down || left || right);
}

// void print(t_game *game)
// {
// 	int i=0,j=0;
// 	for(i = 0; i < game->height;i++)
// 	{
// 		for(j = 0; j< game->width;j++)
// 		{
// 			printf("%c",game->map[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

int	check_valid_map(t_game *game, char *file)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				if (!valid_map_path(game, x, y, 'E'))
					return (0);
				free_map(game, 0, file);
			}
			if (game->map[y][x] == 'C')
			{
				if (!valid_map_path(game, x, y, 'P'))
					return (0);
				free_map(game, 0, file);
			}
		}
	}
	return (1);
}

int	close_game(t_game *game)
{
	if (game)
		free_resources(game);
	exit(0);
	return (0);
}
