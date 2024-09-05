/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kabbas <kabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:34:48 by kabbas            #+#    #+#             */
/*   Updated: 2024/08/12 16:29:48 by kabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../src/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>

# define S 32

typedef enum e_direction {
	IDLE,
	UP,
	DOWN,
	LEFT,
	RIGHT
}	t_direction;

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_enemy
{
	int				x;
	int				y;
	t_img			enemy;
	struct s_enemy	*next;
}	t_enemy;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		**map;
	int			argc;
	char		**argv;
	int			last_enemy_move_time;
	int			last_animation_time;
	t_img		wall;
	t_img		collectible;
	t_img		exit;
	t_img		player;
	t_img		floor;
	int			player_x;
	int			player_y;
	int			collectibles;
	int			moves;
	t_enemy		*enemies;
	int			anim_collectible;
	int			anim_player;
	int			anim_enemy;
	t_direction	direction;
}	t_game;

int		main(int argc, char **av);
void	map(t_game *game, char *map_file);
int		render_map(t_game *game);
void	init_game(t_game *game, char *file);
void	shapes(t_game *game);
void	ft_putstr(char *str);
int		handle_input(int key, t_game *game);
int		close_game(t_game *game);
void	free_resources(t_game *game);
int		check_characters(t_game *game);
int		ft_strchr(const char *s, int c);
int		check_required(t_game *game);
int		valid_map_path(t_game *game, int w, int h, char c);
int		check_valid_map(t_game *game, char *file);
void	free_map(t_game *game, int x, char *file);
void	add_enemy(t_enemy **enemies, int x, int y);
void	free_enemy(t_game *game);
void	move_enemy(t_game *game);
int		check_collision(t_game *game);
int		check_move(t_game *game, int y, int x);
char	*ft_itoa(int n);
void	load_textures(t_game *game);
void	free_textures(t_game *game);
int		end_with(char *src, const char *temp);
int		game_loop(t_game *game);
void	ft_anim_player(t_game *game);
int		ft_anim_player_idle(t_game *game);
int		get_time_in_milliseconds(void);
void	handle_direction(t_game *game, int new_x, int new_y);
int		ft_anim_player_left(t_game *game);
int		ft_anim_player_right(t_game *game);
int		ft_anim_player_up(t_game *game);
int		ft_anim_player_down(t_game *game);
int		check_characters(t_game *game);
#endif