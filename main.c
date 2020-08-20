/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:32:08 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 17:32:22 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main()
{
	t_data data;
	t_texture text;

	text.width = 32;
	text.height = 32;
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 800, 400, "test");
	text.id = mlx_xpm_file_to_image(data.mlx, "tiger.xpm", &text.height, &text.width);
	mlx_put_image_to_window(data.mlx, data.window, text.id, 0, 0);
	mlx_loop(data.mlx);
    return (0);
}
