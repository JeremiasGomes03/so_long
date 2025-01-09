/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeremias <jeremias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 19:07:26 by jeremias          #+#    #+#             */
/*   Updated: 2025/01/08 15:27:49 by jeremias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **grid, int y, int x, t_game *game)
{
	if (y < 0 || x < 0 || y >= game->map->height || x >= game->map->width)
		return ;
	if (grid[y][x] == '1' || grid[y][x] == 'E')
		return ;
	if (grid[y][x] != 'P')
	{
		if (grid[y][x] == '0')
			grid[y][x] = 'o';
		else if (grid[y][x] == 'C')
			grid[y][x] = 'c';
		else
			return ;
	}
	flood_fill(grid, y + 1, x, game);
	flood_fill(grid, y - 1, x, game);
	flood_fill(grid, y, x + 1, game);
	flood_fill(grid, y, x - 1, game);
}

static int	check_exit_access(char **grid, int i, int j, t_game *game)
{
	if (i <= 0
		|| i >= game->map->height - 1 || j <= 0 || j >= game->map->width - 1)
		return (0);
	return ((grid[i][j + 1] == 'E' || grid[i][j - 1] == 'E' ||
			grid[i + 1][j] == 'E' || grid[i - 1][j] == 'E') &&
			(grid[i][j] == 'o' || grid[i][j] == 'c'));
}

static void	restore_grid(char **grid, int i, int j)
{
	if (grid[i][j] == 'o')
		grid[i][j] = '0';
	else if (grid[i][j] == 'c')
		grid[i][j] = 'C';
}

int	validate_path(t_game *game)
{
	int	i;
	int	j;
	int	has_exit_path;

	i = -1;
	has_exit_path = 0;
	flood_fill(game->map->grid, game->player_y, game->player_x, game);
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			if (game->map->grid[i][j] == 'C')
				return (0);
			if (check_exit_access(game->map->grid, i, j, game))
				has_exit_path = 1;
			restore_grid(game->map->grid, i, j);
		}
	}
	return (has_exit_path);
}
