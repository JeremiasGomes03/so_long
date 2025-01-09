/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:32:32 by jeremias          #+#    #+#             */
/*   Updated: 2025/01/07 16:18:00 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= game->map->width)
		return (0);
	if (new_y < 0 || new_y >= game->map->height)
		return (0);
	if (game->map->grid[new_y][new_x] == '1')
		return (0);
	return (1);
}

static void	validate_win(t_game *game)
{
	if (game->map->collectibles > 0)
	{
		game->map->grid[game->player_y][game->player_x] = 'E';
	}
	else
	{
		ft_putstr_fd ("\nYou won in ", 1);
		ft_putnbr_fd (game->moves, 1);
		ft_putstr_fd (" moves!\n", 1);
		mlx_close_window(game->mlx);
	}
}

void	process_move(t_game *game, int new_x, int new_y)
{
	if (game->map->grid[new_y][new_x] == 'C')
	{
		game->map->collectibles--;
		game->map->grid[new_y][new_x] = '0';
		render_tile(game, new_x, new_y);
	}
	if (game->map->grid[new_y][new_x] == 'E')
	{
		validate_win (game);
		if (game->map->collectibles > 0)
			return ;
		return ;
	}
	game->map->grid[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	ft_putstr_fd("Moves: ", 1);
	ft_putnbr_fd(game->moves, 1);
	ft_putstr_fd("\n", 1);
	game->map->grid[new_y][new_x] = 'P';
	mlx_delete_image(game->mlx, game->tiles[2]);
	game->tiles[2] = mlx_texture_to_image(game->mlx, game->textures[2]);
	mlx_image_to_window(game->mlx, game->tiles[2], \
	new_x * TILE_SIZE, new_y * TILE_SIZE);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		new_x;
	int		new_y;

	game = (t_game *)param;
	new_x = game->player_x;
	new_y = game->player_y;
	if (keydata.action != MLX_PRESS)
		return ;
	if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
	else if (keydata.key == MLX_KEY_W)
		new_y--;
	else if (keydata.key == MLX_KEY_S)
		new_y++;
	else if (keydata.key == MLX_KEY_A)
		new_x--;
	else if (keydata.key == MLX_KEY_D)
		new_x++;
	else
		return ;
	if (validate_move(game, new_x, new_y) && keydata.key != MLX_KEY_ESCAPE)
		process_move(game, new_x, new_y);
}
