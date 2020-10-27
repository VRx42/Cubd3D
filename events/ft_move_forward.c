/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:09:55 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:09:58 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_move_forward(t_data *data)
{
	int a;
	int	b;

	a = (int)(data->posx + data->dirx * SPW);
	b = (int)data->posy;
	if (data->map[a][b] == '0')
		data->posx += data->dirx * SPW;
	a = (int)data->posx;
	b = (int)(data->posy + data->diry * SPW);
	if (data->map[a][b] == '0')
		data->posy += data->diry * SPW;
}
