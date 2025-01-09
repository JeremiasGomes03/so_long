/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:22:35 by jerda-si          #+#    #+#             */
/*   Updated: 2025/01/09 10:33:39 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_grid(char **grid, int height)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (i < height)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

void	free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < map->height)
	{
		free(map->grid[i]);
		i++;
	}
	free(map->grid);
	free(map);
}

void	cleanup_game(t_game *game)
{
	cleanup_textures(game);
	if (game->map)
		free_map(game->map);
	if (game->mlx)
	{
		mlx_terminate(game->mlx);
		game->mlx = NULL;
	}
}

static int	is_end_dotber(char *map_file)
{
	int		i;

	i = 0;
	i = ft_strlen(map_file);
	if (map_file[i - 1] != 'r')
		return (0);
	else if (map_file[i - 2] != 'e')
		return (0);
	else if (map_file[i - 3] != 'b')
		return (0);
	else if (map_file[i - 4] != '.')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !is_end_dotber(argv[1]))
	{
		ft_putstr_fd ("Error:\nUsage: ./so_long <map.ber>\n", 1);
		return (0);
	}
	if (!init_game(&game, argv[1]))
	{
		cleanup_game(&game);
		return (0);
	}
	render_map(&game);
	mlx_key_hook(game.mlx, key_hook, &game);
	mlx_loop(game.mlx);
	cleanup_game(&game);
	return (0);
}
