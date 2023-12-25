/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 22:35:59 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 09:04:51 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_enemy(t_game *game)
{
	int	dx;
	int	dy;

	dx = game->player_pos.x - game->enemy_pos.x;
	dy = game->player_pos.y - game->enemy_pos.y;
	if (dx > 0 && enemy_pos_is_valid(game,
			game->enemy_pos.x + 1, game->enemy_pos.y))
		update_enemy_map(game, game->enemy_pos.x + 1, game->enemy_pos.y);
	else if (dy > 0 && enemy_pos_is_valid(game,
			game->enemy_pos.x, game->enemy_pos.y + 1))
		update_enemy_map(game, game->enemy_pos.x, game->enemy_pos.y + 1);
	else if (dx < 0 && enemy_pos_is_valid(game,
			game->enemy_pos.x - 1, game->enemy_pos.y))
		update_enemy_map(game, game->enemy_pos.x - 1, game->enemy_pos.y);
	else if (dy < 0 && enemy_pos_is_valid(game,
			game->enemy_pos.x, game->enemy_pos.y - 1))
		update_enemy_map(game, game->enemy_pos.x, game->enemy_pos.y - 1);
}

void	update_enemy_map(t_game *game, int new_px, int new_py)
{
	game->map[game->enemy_pos.y][game->enemy_pos.x] = '0';
	game->map[new_py][new_px] = 'X';
	if (new_px > game->enemy_pos.x)
		game->enemy_pos.x++;
	else if (new_px < game->enemy_pos.x)
		game->enemy_pos.x--;
	if (new_py > game->enemy_pos.y)
		game->enemy_pos.y++;
	else if (new_py < game->enemy_pos.y)
		game->enemy_pos.y--;
}

void	add_enemy_to_map(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = game->rows;
		while (--x >= 0)
		{
			if (game->map[y][x] == '0')
			{
				game->map[y][x] = 'X';
				game->enemy_pos.x = x;
				game->enemy_pos.y = y;
				return ;
			}
		}
	}
}

int	enemy_pos_is_valid(t_game *game, int new_px, int new_py)
{
	if (game->map[new_py][new_px] == '0' || game->map[new_py][new_px] == 'P')
		return (1);
	return (0);
}
