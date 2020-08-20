/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turning_cam.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:09:16 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:09:21 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	turning_cam(t_data *data, double speed)
{
	double	olddirx;
	double	olddplanex;

	olddirx = data->dirx;
	data->dirx = data->dirx * cos(speed) - data->diry * sin(speed);
	data->diry = olddirx * sin(speed) + data->diry * cos(speed);
	olddplanex = data->planex;
	data->planex = data->planex * cos(speed) - data->planey * sin(speed);
	data->planey = olddplanex * sin(speed) + data->planey * cos(speed);
}
