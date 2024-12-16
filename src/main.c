/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerda-si <jerda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:22:35 by jerda-si          #+#    #+#             */
/*   Updated: 2024/12/13 19:55:35 by jerda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include <stdlib.h>
#include <stdio.h>
#include "../libraries/MLX42/include/MLX42/MLX42.h"

#define WIDTH 640
#define HEIGHT 360

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void close_program(void *param)
{
    mlx_t *mlx = (mlx_t *)param;
    mlx_terminate(mlx);
    exit(EXIT_SUCCESS);
}

int32_t main(void)
{
    mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "URSO PAU NO CU", true);
    if (!mlx)
        error();

    mlx_texture_t *text_su = mlx_load_png("./assets/urso.png");
    if (!text_su)
    {
        printf("Falha ao carregar o PNG.\n");
        error();
    }
    mlx_image_t *img_su = mlx_texture_to_image(mlx, text_su);
    if (!img_su)
    {
        printf("Falha ao converter a textura em imagem.\n");
        error();
    }
    mlx_image_to_window(mlx, img_su, 2, 4);

    // Adicionar hook para fechar
    mlx_close_hook(mlx, close_program, mlx);

    mlx_loop(mlx);
    mlx_terminate(mlx);
    return (EXIT_SUCCESS);
}

