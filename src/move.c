#include "so_long.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game *game = (t_game *)param;

    if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
    {
        if (keydata.key == MLX_KEY_ESCAPE)
		    mlx_close_window(game->mlx);
        if (keydata.key == MLX_KEY_W && game->player_y > 0)
            game->player_y -= TILE_SIZE;
        else if (keydata.key == MLX_KEY_S && game->player_y < HEIGHT - TILE_SIZE)
            game->player_y += TILE_SIZE;
        else if (keydata.key == MLX_KEY_A && game->player_x > 0)
            game->player_x -= TILE_SIZE;
        else if (keydata.key == MLX_KEY_D && game->player_x < WIDTH - TILE_SIZE)
            game->player_x += TILE_SIZE;

        // atualiza a posição do personagem
        game->player_img->instances[0].x = game->player_x;
        game->player_img->instances[0].y = game->player_y;
    }
}


