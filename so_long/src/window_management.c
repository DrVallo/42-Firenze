/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:20:54 by avallini          #+#    #+#             */
/*   Updated: 2023/12/24 18:14:33 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate_window_size(t_game *game)
{
	int	screen_x;
	int	screen_y;
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->cols)
	{
		y = 0;
		while (y < game->rows)
		{
			screen_x = sprite_to_screen_x(x, y);
			screen_y = sprite_to_screen_y(x, y);
			if (screen_x > game->mlx.window_w)
				game->mlx.window_w = screen_x;
			if (screen_y > game->mlx.window_h)
				game->mlx.window_h = screen_y;
			y++;
		}
		x++;
	}
	game->mlx.window_w += SPRITE_W;
	game->mlx.window_h += SPRITE_H;
}

int	sprite_to_screen_x(int x, int y)
{
	return (x * 0.5 * SPRITE_W + y * -0.5 * SPRITE_W
		- SPRITE_W + (SCREEN_W * 0.35));
}

int	sprite_to_screen_y(int x, int y)
{
	return (x * 0.25 * SPRITE_H + y * 0.25 * SPRITE_H
		- SPRITE_H + (SCREEN_H * 0.30));
}

void	set_background_color(t_game *game, int color)
{
	int	i;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	*data;

	i = 0;
	game->mlx.bg = mlx_new_image(game->mlx.mlx,
			game->mlx.window_w, game->mlx.window_h);
	data = (int *)mlx_get_data_addr(game->mlx.bg,
			&bits_per_pixel, &line_length, &endian);
	while (i < game->mlx.window_w * game->mlx.window_h)
		data[i++] = color;
	mlx_put_image_to_window(game->mlx.mlx,
		game->mlx.mlx_win, game->mlx.bg, 0, 0);
}
