/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 19:05:37 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 16:02:48 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_DOWN 65364

# define KEY_ESC 65307

# define SPRITE_W 128
# define SPRITE_H 128

# define SCREEN_W 1280
# define SCREEN_H 720

# define BG_COLOR 0x172139

# include "../mlx/mlx.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <limits.h>

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;

	void	*sprite_grass;
	void	*sprite_rock;
	void	*sprite_exit;
	void	*sprite_player;
	void	*sprite_player_2;
	void	*sprite_player_3;
	void	*sprite_enemy;
	void	*sprite_enemy_2;
	void	*sprite_enemy_3;
	void	*sprite_player_exit;
	void	*sprite_player_dead;
	void	*sprite_collectible;
	void	*bg;
	int		window_w;
	int		window_h;
	int		sprite_w;
	int		sprite_h;
}	t_mlx;

typedef struct s_game
{
	t_mlx	mlx;
	char	**map;
	int		rows;
	int		cols;
	int		collectibles;
	int		moves;
	int		enemy_move;
	int		anim_frame;
	t_pos	player_pos;
	t_pos	enemy_pos;

}	t_game;

void	calculate_window_size(t_game *game);
int		sprite_to_screen_x(int x, int y);
int		sprite_to_screen_y(int x, int y);
void	set_background_color(t_game *game, int color);

int		read_map(t_game *game, char *map_path);
void	set_map(t_game *game, char *tmp_map);
void	draw_map(t_game *game);
void	*get_sprite_to_data(t_game *game, char c);
void	*get_sprite_frame_to_data(t_game *game, char c);
int		check_map_file_extension(char *file);

int		key_hook(int keycode, t_game *game);
int		game_loop(t_game *game);
int		expose_window(t_game *game);
int		close_window(t_game *game);
void	close_window_anim(t_game *game);

int		check_map(t_game *game);
int		map_char_is_valid(t_game *game);
int		check_required_char(t_game *game);
int		check_valid_wall_border(t_game *game);
int		check_valid_path(t_game *game);
char	**copy_map(t_game *game);
void	flood_fill(char **map, int x, int y);

void	move_player(t_game *game, char key);
int		update_map(t_game *game, int new_px, int new_py);
void	check_finish_game(t_game *game);

void	move_enemy(t_game *game);
void	add_enemy_to_map(t_game *game);
void	update_enemy_map(t_game *game, int new_px, int new_py);
int		enemy_pos_is_valid(t_game *game, int new_px, int new_py);

void	init_window(t_game *game);
void	init_game_var(t_game *game);
int		init_sprites(t_game *game);
int		init_sprites_anim(t_game *game);
void	free_map(char **map);

int		str_len(char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*add_char_to_str(char *str, char c, t_game *game);
char	*ft_itoa(int n);
int		n_len(int n);

#endif
