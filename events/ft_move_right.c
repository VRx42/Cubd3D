/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:10:11 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:10:13 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_move_right(t_data *data)
{
	int	a;
	int	b;

	a = (int)(data->posx + data->planex * SPW);
	b = (int)data->posy;
	if (data->map[a][b] == '0')
		data->posx += data->planex * SPW;
	a = (int)data->posx;
	b = (int)(data->posy + data->planey * SPW);
	if (data->map[a][b] == '0')
		data->posy += data->planey * SPW;
}
