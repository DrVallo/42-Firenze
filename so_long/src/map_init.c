/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:24:18 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 09:59:32 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_game *game, char *map_path)
{
	int		map;
	int		buf_size;
	char	*buf;
	char	*tmp_map;

	tmp_map = NULL;
	buf_size = 1;
	map = open(map_path, O_RDONLY);
	if (map < 0)
	{
		ft_putstr_fd("Error\nError in map reading.\n", 1);
		return (0);
	}
	buf = (char *)malloc(sizeof(char));
	buf_size = read(map, buf, 1);
	while (buf_size > 0)
	{
		tmp_map = add_char_to_str(tmp_map, *buf, game);
		buf_size = read(map, buf, 1);
	}
	free(buf);
	close(map);
	set_map(game, tmp_map);
	return (1);
}

void	set_map(t_game *game, char *tmp_map)
{
	int	i;
	int	j;
	int	k;
	int	split_i;
	int	s_len;

	i = -1;
	k = 0;
	split_i = -1;
	s_len = str_len(tmp_map);
	game->map = (char **)malloc(sizeof(char *) * (game->rows + 1));
	while (++i <= s_len)
	{
		if (tmp_map[i] == '\n' || !tmp_map[i])
		{
			j = -1;
			game->map[++split_i] = (char *)malloc(sizeof(char) * ((i - k) + 1));
			while (k < i)
				game->map[split_i][++j] = tmp_map[k++];
			game->map[split_i][++j] = '\0';
			k++;
		}
	}
	game->map[++split_i] = NULL;
	free(tmp_map);
}

int	check_map_file_extension(char *file)
{
	int	ext;

	ext = str_len(file) - 4;
	if (ext < 1)
	{
		ft_putstr_fd("Error\nA map with a .ber extension is required.\n", 1);
		return (0);
	}
	if (file[ext] == '.' && file[ext + 1] == 'b'
		&& file[ext + 2] == 'e' && file[ext + 3] == 'r')
		return (1);
	ft_putstr_fd("Error\nA map with a .ber extension is required.\n", 1);
	return (0);
}
