/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycasting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 11:00:20 by vronchin          #+#    #+#             */
/*   Updated: 2020/07/31 12:53:32 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int				get_endy(int sp_h, t_data *data)
{
	int endy;

	endy = sp_h / 2 + data->wd_h / 2;
	if (endy >= data->wd_h)
		endy = data->wd_h;
	return (endy);
}

double			get_tx(t_data *data, t_sprite *tab_sprite, int i)
{
	double	spx;
	double	spy;
	double	invdet;
	double	transx;

	spx = tab_sprite[i].x - data->posx;
	spy = tab_sprite[i].y - data->posy;
	invdet = 1.0 / (data->planex * data->diry - data->dirx * data->planey);
	transx = invdet * (data->diry * spx - data->dirx * spy);
	return (transx);
}

double			get_ty(t_data *data, t_sprite *tab_sprite, int i)
{
	double	spx;
	double	spy;
	double	invdet;
	double	ty;

	spx = tab_sprite[i].x - data->posx;
	spy = tab_sprite[i].y - data->posy;
	invdet = 1.0 / (data->planex * data->diry - data->dirx * data->planey);
	ty = invdet * (-data->planey * spx + data->planex * spy);
	return (ty);
}

int				get_yt(t_data *data, int y, int sp_h, t_txt txtsp)
{
	int yt;
	int	d;

	d = (y) * 256 - data->wd_h * 128 + sp_h * 128;
	yt = ((d * txtsp.height) / sp_h) / 256;
	return (yt);
}
