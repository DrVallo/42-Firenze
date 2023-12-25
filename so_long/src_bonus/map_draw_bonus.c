/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_draw_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 09:50:51 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 08:53:03 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;
	char	*nbr;

	y = -1;
	nbr = ft_itoa(game->moves);
	mlx_put_image_to_window(game->mlx.mlx,
		game->mlx.mlx_win, game->mlx.bg, 0, 0);
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
	mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 32, 32,
		0xFFFFFF, "Moves:");
	mlx_string_put(game->mlx.mlx, game->mlx.mlx_win, 96, 32, 0xFFFFFF, nbr);
	free(nbr);
}

void	*get_sprite_to_data(t_game *game, char c)
{
	if (c == '1')
		return (game->mlx.sprite_rock);
	else if (c == 'E')
		return (game->mlx.sprite_exit);
	else if (c == 'P' || c == 'X')
		return (get_sprite_frame_to_data(game, c));
	else if (c == 'C')
		return (game->mlx.sprite_collectible);
	else if (c == 'F')
		return (game->mlx.sprite_player_exit);
	else if (c == 'D')
		return (game->mlx.sprite_player_dead);
	return (game->mlx.sprite_grass);
}

void	*get_sprite_frame_to_data(t_game *game, char c)
{
	if (c == 'P')
	{
		if (game->anim_frame <= 8)
			return (game->mlx.sprite_player);
		else if (game->anim_frame == 9)
			return (game->mlx.sprite_player_2);
		else if (game->anim_frame == 10)
			return (game->mlx.sprite_player_3);
	}
	else if (c == 'X')
	{
		if (game->anim_frame <= 8)
			return (game->mlx.sprite_enemy);
		else if (game->anim_frame == 9)
			return (game->mlx.sprite_enemy_2);
		else if (game->anim_frame == 10)
			return (game->mlx.sprite_enemy_3);
	}
	return (NULL);
}
