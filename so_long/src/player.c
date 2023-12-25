/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:27:42 by avallini          #+#    #+#             */
/*   Updated: 2023/12/24 10:03:13 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, char key)
{
	int	x;
	int	y;

	x = game->player_pos.x;
	y = game->player_pos.y;
	if (game->map[y][x] == 'F')
		return ;
	if (key == 'W' && !update_map(game, x, y - 1))
		return ;
	else if (key == 'S' && !update_map(game, x, y + 1))
		return ;
	else if (key == 'A' && !update_map(game, x - 1, y))
		return ;
	else if (key == 'D' && !update_map(game, x + 1, y))
		return ;
	update_moves_count(game);
	draw_map(game);
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

void	update_moves_count(t_game *game)
{
	game->moves++;
	ft_putnbr_fd(game->moves, 1);
	write(1, "\n", 1);
}

void	check_finish_game(t_game *game)
{
	if (game->collectibles == 0)
	{
		if (game->map[game->player_pos.y][game->player_pos.x] == 'F')
		{
			ft_putstr_fd("YOU WIN! Movement needed: ", 1);
			ft_putnbr_fd(game->moves, 1);
			ft_putstr_fd(".\nPress ESC to close the game.\n", 1);
		}
	}
}
