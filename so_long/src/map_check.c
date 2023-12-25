/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:14:18 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 09:44:39 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(t_game *game)
{
	int	i;

	i = 1;
	game->cols = str_len(game->map[0]);
	if (!map_char_is_valid(game))
		return (0);
	while (i < game->rows)
	{
		if (game->cols != str_len(game->map[i]))
			return (0);
		i++;
	}
	if (game->rows == game->cols)
		return (0);
	if (!check_required_char(game) || !check_valid_wall_border(game)
		|| !check_valid_path(game))
		return (0);
	return (1);
}

int	map_char_is_valid(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = -1;
	if (game->map[0][0] == '\n')
		return (0);
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			c = game->map[y][x];
			if ((c != '1' && c != '0' && c != 'C' && c != 'E' && c != 'P')
				|| (x == 0 && game->map[y][x] == '\n'))
				return (0);
		}
	}
	return (1);
}

int	check_required_char(t_game *game)
{
	int	c_exit;
	int	c_start;
	int	x;
	int	y;

	c_exit = 0;
	c_start = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'P' && ++c_start)
			{
				game->player_pos.x = x;
				game->player_pos.y = y;
			}
			else if (game->map[y][x] == 'E')
				c_exit++;
		}
	}
	if (game->collectibles == 0 || c_exit > 1 || c_start > 1)
		return (0);
	return (1);
}

int	check_valid_wall_border(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (y == 0 || y == game->rows - 1)
			{
				if (game->map[y][x] != '1')
					return (0);
			}
			if ((x == 0 || x == game->cols - 1) && y > 0 && y < game->rows - 1)
			{
				if (game->map[y][x] != '1')
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_valid_path(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		k;

	i = -1;
	tmp_map = copy_map(game);
	flood_fill(tmp_map, game->player_pos.x, game->player_pos.y);
	while (tmp_map[++i])
	{
		k = -1;
		while (tmp_map[i][++k])
		{
			if (tmp_map[i][k] == 'E' || tmp_map[i][k] == 'C')
			{
				free_map(tmp_map);
				return (0);
			}
		}
	}
	free_map(tmp_map);
	return (1);
}
