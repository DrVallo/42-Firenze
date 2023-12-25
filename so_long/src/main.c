/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avallini <avallini@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 18:09:33 by avallini          #+#    #+#             */
/*   Updated: 2023/12/25 15:55:50 by avallini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	init_sprites(t_game *game)
{
	game->mlx.sprite_grass = mlx_xpm_file_to_image(game->mlx.mlx,
			"./textures/grass.xpm", &game->mlx.sprite_w, &game->mlx.sprite_h);
	game->mlx.sprite_rock = mlx_xpm_file_to_image(game->mlx.mlx,
			"./textures/rock.xpm", &game->mlx.sprite_w, &game->mlx.sprite_h);
	game->mlx.sprite_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"./textures/exit.xpm", &game->mlx.sprite_w, &game->mlx.sprite_h);
	game->mlx.sprite_player = mlx_xpm_file_to_image(game->mlx.mlx,
			"./textures/player.xpm", &game->mlx.sprite_w, &game->mlx.sprite_h);
	game->mlx.sprite_collectible = mlx_xpm_file_to_image(game->mlx.mlx,
			"./textures/collectible.xpm",
			&game->mlx.sprite_w, &game->mlx.sprite_h);
	game->mlx.sprite_player_exit = mlx_xpm_file_to_image(game->mlx.mlx,
			"./textures/player_exit.xpm",
			&game->mlx.sprite_w, &game->mlx.sprite_h);
	if (!game->mlx.sprite_grass || !game->mlx.sprite_rock
		|| !game->mlx.sprite_exit || !game->mlx.sprite_player
		|| !game->mlx.sprite_collectible || !game->mlx.sprite_player_exit)
	{
		ft_putstr_fd("Error\nError in loading sprites.\n", 1);
		return (0);
	}
	return (1);
}

void	init_game_var(t_game *game)
{
	game->map = NULL;
	game->rows = 1;
	game->cols = 0;
	game->collectibles = 0;
	game->moves = 0;
	game->mlx.window_w = 1;
	game->mlx.window_h = 1;
	game->player_pos.x = 0;
	game->player_pos.y = 0;
	game->mlx.sprite_grass = NULL;
	game->mlx.sprite_rock = NULL;
	game->mlx.sprite_exit = NULL;
	game->mlx.sprite_player = NULL;
	game->mlx.sprite_player_exit = NULL;
	game->mlx.sprite_collectible = NULL;
	game->mlx.bg = NULL;
}

void	init_window(t_game *game)
{
	calculate_window_size(game);
	game->mlx.mlx = mlx_init();
	game->mlx.mlx_win = mlx_new_window(game->mlx.mlx,
			game->mlx.window_w, game->mlx.window_h, "so_long");
	mlx_hook(game->mlx.mlx_win, 17, 0, close_window, game);
	mlx_hook(game->mlx.mlx_win, 12, 1L << 15, expose_window, game);
	mlx_hook(game->mlx.mlx_win, 2, 1L << 0, key_hook, game);
	set_background_color(game, BG_COLOR);
}

int	main(int argc, char *argv[])
{
	t_game	game;

	init_game_var(&game);
	if (argc != 2)
	{
		ft_putstr_fd("Error\nHow to use: ./so_long <map_file_path>\n", 1);
		return (0);
	}
	if (!check_map_file_extension(argv[1]) || !read_map(&game, argv[1]))
		return (0);
	if (!check_map(&game))
	{
		free_map(game.map);
		ft_putstr_fd("Error\nError in map configuration.\n", 1);
		return (0);
	}
	init_window(&game);
	if (!init_sprites(&game))
		close_window(&game);
	expose_window(&game);
	mlx_loop(game.mlx.mlx);
}
