/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:27:42 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 08:47:05 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_player(t_game *game, char key)
{
	int	x;
	int	y;

	x = game->player_pos.x;
	y = game->player_pos.y;
	if (game->map[y][x] == 'F' || game->map[y][x] == 'D')
		return ;
	if (key == 'W' && !update_map(game, x, y - 1))
		return ;
	else if (key == 'S' && !update_map(game, x, y + 1))
		return ;
	else if (key == 'A' && !update_map(game, x - 1, y))
		return ;
	else if (key == 'D' && !update_map(game, x + 1, y))
		return ;
	game->moves++;
	if (game->enemy_move)
	{
		move_enemy(game);
		game->enemy_move = 0;
	}
	else
		game->enemy_move = 1;
	expose_window(game);
	check_finish_game(game);
}

int	update_map(t_game *game, int new_px, int new_py)
{
	if (game->map[new_py][new_px] == '1')
		return (0);
	if (game->map[new_py][new_px] == 'E' && game->collectibles > 0)
		return (0);
	if (game->map[new_py][new_px] == 'C')
		game->collectibles--;
	game->map[game->player_pos.y][game->player_pos.x] = '0';
	if (game->map[new_py][new_px] == 'E' && game->collectibles == 0)
		game->map[new_py][new_px] = 'F';
	else
		game->map[new_py][new_px] = 'P';
	if (new_px > game->player_pos.x)
		game->player_pos.x++;
	else if (new_px < game->player_pos.x)
		game->player_pos.x--;
	else if (new_py > game->player_pos.y)
		game->player_pos.y++;
	else if (new_py < game->player_pos.y)
		game->player_pos.y--;
	return (1);
}

void	check_finish_game(t_game *game)
{
	if (game->map[game->player_pos.y][game->player_pos.x] == 'X')
	{
		game->map[game->player_pos.y][game->player_pos.x] = 'D';
		expose_window(game);
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 32, 64,
			0xFFFFFF, "YOU LOSE");
		mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 32, 96,
			0xFFFFFF, "Press ESC to close the game.");
	}
	if (game->collectibles == 0)
	{
		if (game->map[game->player_pos.y][game->player_pos.x] == 'F')
		{
			mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 32, 64,
				0xFFFFFF, "YOU WIN!");
			mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 32, 96,
				0xFFFFFF, "Press ESC to close the game.");
		}
	}
}
