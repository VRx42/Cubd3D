/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:30:40 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 17:31:06 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_exit_cube(t_data *data)
{
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx, data->img.img_ptr);
	if (data->list.east.id)
		mlx_destroy_image(data->mlx, data->list.east.id);
	if (data->list.west.id)
		mlx_destroy_image(data->mlx, data->list.west.id);
	if (data->list.north.id)
		mlx_destroy_image(data->mlx, data->list.north.id);
	if (data->list.south.id)
		mlx_destroy_image(data->mlx, data->list.south.id);
	if (data->list.sprite.id)
		mlx_destroy_image(data->mlx, data->list.sprite.id);
	exit(1);
}
