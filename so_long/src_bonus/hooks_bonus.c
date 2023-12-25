/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:18:15 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 16:02:12 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_game *game)
{
	if (game->mlx.sprite_grass != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_grass);
	if (game->mlx.sprite_rock != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_rock);
	if (game->mlx.sprite_exit != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_exit);
	if (game->mlx.sprite_player != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_player);
	if (game->mlx.sprite_collectible != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_collectible);
	if (game->mlx.sprite_player_exit != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_player_exit);
	if (game->mlx.bg != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.bg);
	close_window_anim(game);
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	mlx_destroy_display(game->mlx.mlx);
	free_map(game->map);
	free(game->mlx.mlx);
	exit(0);
}

void	close_window_anim(t_game *game)
{
	if (game->mlx.sprite_player_2 != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_player_2);
	if (game->mlx.sprite_player_3 != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_player_3);
	if (game->mlx.sprite_enemy != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_enemy);
	if (game->mlx.sprite_enemy_2 != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_enemy_2);
	if (game->mlx.sprite_enemy_3 != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_enemy_3);
	if (game->mlx.sprite_player_dead != NULL)
		mlx_destroy_image(game->mlx.mlx, game->mlx.sprite_player_dead);
}

int	expose_window(t_game *game)
{
	mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
	draw_map(game);
	return (0);
}

int	key_hook(int keycode, t_game *game)
{
	(void)game;
	if (keycode == KEY_W || keycode == KEY_UP)
		move_player(game, 'W');
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		move_player(game, 'A');
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		move_player(game, 'D');
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		move_player(game, 'S');
	else if (keycode == KEY_ESC)
		close_window(game);
	return (0);
}

int	game_loop(t_game *game)
{
	static int	frame;

	if (++frame > 2400)
	{
		if (++game->anim_frame > 10)
			game->anim_frame = 0;
		if (game->map[game->player_pos.y][game->player_pos.x] == 'P')
			expose_window(game);
		frame = 0;
	}
	return (0);
}
