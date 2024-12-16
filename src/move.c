/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 19:56:05 by jerda-si          #+#    #+#             */
/*   Updated: 2024/12/13 20:12:13 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//funcao para mover o boneco cada vez que o botao e clicado
void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
		if (keydata.key == MLX_KEY_ESCAPE)
			mlx_close_window(game->mlx);
        if (keydata.key == MLX_KEY_W)
            game->player_y -= TILE_SIZE;
        else if (keydata.key == MLX_KEY_S)
            game->player_y += TILE_SIZE;
        else if (keydata.key == MLX_KEY_A)
            game->player_x -= TILE_SIZE;
        else if (keydata.key == MLX_KEY_D)
            game->player_x += TILE_SIZE;

        mlx_image_to_window(game->mlx, game->player_img, game->player_x, game->player_y);
    }
}