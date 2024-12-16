/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:31:15 by jerda-si          #+#    #+#             */
/*   Updated: 2024/12/16 17:31:38 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "../include/MLX42/MLX42.h"
# include "../libraries/libft/libft.h"

# define TILE_SIZE 64
# define WIDTH 640
# define HEIGHT 480

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		collectibles;
}	t_map;

typedef struct s_game
{
	mlx_t			*mlx;
	mlx_image_t		*tiles[6];
	mlx_texture_t	*textures[6];
	mlx_image_t     *player_img;
	int				player_x;
	int				player_y;
	int				moves;
	t_map			*map;
}	t_game;

void key_hook(mlx_key_data_t keydata, void *param);

#endif