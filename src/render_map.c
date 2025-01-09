/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremias <jeremias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:47:03 by jeremias          #+#    #+#             */
/*   Updated: 2025/01/08 19:37:56 by jeremias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	cleanup_textures(t_game *game)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (game->tiles[i])
		{
			mlx_delete_image(game->mlx, game->tiles[i]);
			game->tiles[i] = NULL;
		}
		if (game->textures[i])
		{
			mlx_delete_texture(game->textures[i]);
			game->textures[i] = NULL;
		}
		i++;
	}
}

void	render_tile(t_game *game, int x, int y)
{
	char	tile;

	tile = game->map->grid[y][x];
	if (tile == '0')
		mlx_image_to_window(game->mlx,
			game->tiles[0], x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'C')
		mlx_image_to_window(game->mlx,
			game->tiles[3], x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
		mlx_image_to_window(game->mlx,
			game->tiles[2], x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx,
			game->tiles[4], x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_tile(t_game *game, int x, int y, char tile)
{
	if (tile == '1')
		mlx_image_to_window(game->mlx, game->tiles[1],
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'P')
	{
		game->player_x = x;
		game->player_y = y;
		mlx_image_to_window(game->mlx, game->tiles[2],
			x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (tile == 'C')
		mlx_image_to_window(game->mlx, game->tiles[3],
			x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == 'E')
		mlx_image_to_window(game->mlx, game->tiles[4],
			x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			mlx_image_to_window(game->mlx, game->tiles[0],
				x * TILE_SIZE, y * TILE_SIZE);
			draw_tile(game, x, y, game->map->grid[y][x]);
			x++;
		}
		y++;
	}
}
