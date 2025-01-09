/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremias <jeremias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:49:45 by jeremias          #+#    #+#             */
/*   Updated: 2025/01/08 19:46:13 by jeremias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	load_textures(t_game *game)
{
	int	i;

	i = 0;
	game->textures[0] = mlx_load_png("./assets/bottom.png");
	game->textures[1] = mlx_load_png("./assets/wall.png");
	game->textures[2] = mlx_load_png("./assets/character.png");
	game->textures[3] = mlx_load_png("./assets/collectible.png");
	game->textures[4] = mlx_load_png("./assets/portal.png");
	while (i < 5)
	{
		game->tiles[i] = mlx_texture_to_image(game->mlx, game->textures[i]);
		if (!game->textures[i] || !game->tiles[i])
		{
			cleanup_textures(game);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	init_mlx(t_game *game)
{
	game->mlx = mlx_init(game->map->width * TILE_SIZE,
			game->map->height * TILE_SIZE, "so_long", true);
	if (!game->mlx)
	{
		return (0);
	}
	if (!load_textures(game))
	{
		ft_putstr_fd("Error:\nFailed to load textures\n", 1);
		cleanup_game(game);
		return (0);
	}
	return (1);
}

int	init_game(t_game *game, char *map_file)
{
	ft_memset(game, 0, sizeof(t_game));
	game->moves = 0;
	game->map = read_map(map_file);
	if (!game->map)
	{
		ft_putstr_fd("Error:\nInvalid map!\n", 2);
		return (0);
	}
	ft_find_char('P', game);
	if (!validate_map(game->map, game))
		return (0);
	return (init_mlx(game));
}
