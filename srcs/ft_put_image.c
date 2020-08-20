/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:31:43 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 17:31:56 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_image(t_data *data)
{
	double *zbuffer;

	zbuffer = (double*)malloc(sizeof(double) * data->wd_w);
	ft_raycasting(data, &data->list, zbuffer);
	if (data->nbsprite)
		ft_raycasting_sprite(data, data->tab_sprite, data->list.sprite,\
		 zbuffer);
	mlx_put_image_to_window(data->mlx, data->window, data->img.img_ptr, 0, 0);
}
