/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:50:51 by avallini          #+#    #+#             */
/*   Updated: 2023/12/24 22:53:32 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			img = get_sprite_to_data(game, game->map[y][x]);
			mlx_put_image_to_window(game->mlx.mlx, game->mlx.mlx_win,
				img, sprite_to_screen_x(x, y), sprite_to_screen_y(x, y));
		}
	}
}

void	*get_sprite_to_data(t_game *game, char c)
{
	if (c == '1')
		return (game->mlx.sprite_rock);
	else if (c == 'E')
		return (game->mlx.sprite_exit);
	else if (c == 'P')
		return (game->mlx.sprite_player);
	else if (c == 'C')
		return (game->mlx.sprite_collectible);
	else if (c == 'F')
		return (game->mlx.sprite_player_exit);
	return (game->mlx.sprite_grass);
}
