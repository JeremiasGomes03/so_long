/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 18:58:57 by jeremias          #+#    #+#             */
/*   Updated: 2025/01/07 17:20:51 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_is_rectangular(t_map *map)
{
	int	i;
	int	line_length;

	i = 0;
	if (map->height == map->width)
		return (0);
	while (i < map->height)
	{
		line_length = ft_strlen(map->grid[i]);
		if (line_length != map->width)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_count_elements(t_map *map, int *player, int *exit, int *collect)
{
	int	y;
	int	x;

	*player = 0;
	*exit = 0;
	*collect = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == 'P')
				(*player)++;
			else if (map->grid[y][x] == 'E')
				(*exit)++;
			else if (map->grid[y][x] == 'C')
				(*collect)++;
			x++;
		}
		y++;
	}
	map->collectibles = *collect;
	return (*player == 1 && *exit == 1 && map->collectibles >= 1);
}

void	ft_find_char(char c, t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->map->height)
	{
		x = 0;
		while (x < game->map->width)
		{
			if (game->map->grid[y][x] == c)
			{
				game->player_y = y;
				game->player_x = x;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	validate_map(t_map *map, t_game *game)
{
	int	player;
	int	exit;
	int	collect;

	if (!map || map->height == 0 || map->width == 0)
		return (0);
	if (!validate_path(game))
		return (ft_putstr_fd("Error:\nInvalid path!\n", 2), 0);
	if (!ft_is_rectangular(map))
		return (ft_putstr_fd("Error:\nMap is not rectangular!\n", 2), 0);
	if (!ft_check_walls(map))
		return (ft_putstr_fd("Error:\nMap is not surrounded for walls!\n", 2),
			0);
	if (!ft_count_elements(map, &player, &exit, &collect))
		return (ft_putstr_fd("Error:\nInvalid numbers of elements!\n", 2), 0);
	return (1);
}
