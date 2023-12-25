/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 01:47:06 by avallini          #+#    #+#             */
/*   Updated: 2023/12/24 01:47:36 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_game *game)
{
	char	**tmp_map;
	int		i;
	int		k;

	i = -1;
	tmp_map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	while (++i < game->rows)
	{
		k = -1;
		tmp_map[i] = (char *)malloc(sizeof(char) * (game->cols + 1));
		while (++k < game->cols)
			tmp_map[i][k] = game->map[i][k];
		tmp_map[i][k] = '\0';
	}
	tmp_map[i] = NULL;
	return (tmp_map);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}
