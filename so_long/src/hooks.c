/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:18:15 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 15:53:38 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_destroy_window(game->mlx.mlx, game->mlx.mlx_win);
	mlx_destroy_display(game->mlx.mlx);
	free_map(game->map);
	free(game->mlx.mlx);
	exit(0);
}

int	expose_window(t_game *game)
{
	mlx_clear_window(game->mlx.mlx, game->mlx.mlx_win);
	mlx_put_image_to_window(game->mlx.mlx,
		game->mlx.mlx_win, game->mlx.bg, 0, 0);
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
