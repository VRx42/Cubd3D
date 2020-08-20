/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:08:47 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:08:54 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_left(t_data *data)
{
	int a;
	int	b;

	a = (int)(data->posx - data->planex * SPW);
	b = (int)data->posy;
	if (data->map[a][b] == '0')
		data->posx -= data->planex * SPW;
	a = (int)data->posx;
	b = (int)(data->posy - data->planey * SPW);
	if (data->map[a][b] == '0')
		data->posy -= data->planey * SPW;
}
