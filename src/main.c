/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:22:35 by jerda-si          #+#    #+#             */
/*   Updated: 2024/12/16 19:30:44 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char **argv)
{
    t_game game;

    //funcão para iniaci
    //inicializa tudo
    game.mlx = mlx_init(WIDTH, HEIGHT, "URSO F.D.P", true);
    if (!game.mlx)
        return (EXIT_FAILURE);
    //carrega a imagem do personagem
    mlx_texture_t *player_texture = mlx_load_png("./assets/urso.png");
    if (!player_texture)
    {
        printf("Erro ao carregar a textura!\n");
        return (EXIT_FAILURE);
    }
    game.player_img = mlx_texture_to_image(game.mlx, player_texture);
    mlx_delete_texture(player_texture);
   //add img na tela
    mlx_image_to_window(game.mlx, game.player_img, 0, 0);
    game.player_x = 0;
    game.player_y = 0;
    //registra a movimentação do personagem
    mlx_key_hook(game.mlx, key_hook, &game);
    //loop principal pra fazer tudo funcionar 
    mlx_loop(game.mlx);
    mlx_terminate(game.mlx);
    return (EXIT_SUCCESS);
}

