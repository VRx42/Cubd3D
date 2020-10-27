/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_sprite.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 12:45:24 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/25 12:55:30 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static	void	sort_sprite(t_data *data, t_sprite *tab_sprite)
{
	t_sprite	tmp;
	double		dista;
	double		distb;
	int			i;

	i = 0;
	while (i < data->nbsprite - 1)
	{
		dista = ((data->posx - tab_sprite[i].x) * \
		(data->posx - tab_sprite[i].x) + (data->posy - tab_sprite[i].y) \
		* (data->posy - tab_sprite[i].y));
		distb = ((data->posx - tab_sprite[i + 1].x) * \
		(data->posx - tab_sprite[i + 1].x) + (data->posy - tab_sprite[i + 1].y)\
		* (data->posy - tab_sprite[i + 1].y));
		if (dista < distb)
		{
			tmp = tab_sprite[i];
			tab_sprite[i] = tab_sprite[i + 1];
			tab_sprite[i + 1] = tmp;
			i = 0;
		}
		i++;
	}
}

int				get_startx(int sp_w, int sp)
{
	int startx;

	startx = -sp_w / 2 + sp;
	if (startx < 0)
		startx = 0;
	return (startx);
}

int				get_endx(int sp_w, int sp, t_data *data)
{
	int endx;

	endx = sp_w / 2 + sp;
	if (endx >= data->wd_w)
		endx = data->wd_w;
	return (endx);
}

void			ft_sprite_display(double ty, t_data *data, t_txt txtsp, int s)
{
	int	yt;
	int	xt;
	int	y;
	int sp_h;

	sp_h = abs((int)(data->wd_h / (ty)));
	xt = (int)(256 * (s - (-data->sp_w / 2 + data->sp)) * txtsp.width \
	/ data->sp_w) / 256;
	y = fmax(-sp_h / 2 + data->wd_h / 2, 0);
	while (y < get_endy(sp_h, data))
	{
		yt = get_yt(data, y, sp_h, txtsp);
		if (txtsp.data[yt * txtsp.width + xt] != 0)
			data->img.data[y * data->wd_w - 1 + s] = \
			txtsp.data[yt * txtsp.width + xt];
		y++;
	}
}

void			ft_raycasting_sprite(t_data *data, t_sprite *tab_sprite, \
t_txt txtsp, double *zbuf)
{
	int		i;
	int		s;
	double	ty;

	i = 0;
	sort_sprite(data, tab_sprite);
	while (i < data->nbsprite)
	{
		ty = get_ty(data, tab_sprite, i);
		data->sp = (int)((data->wd_w / 2) *\
		(1 + get_tx(data, tab_sprite, i) / ty));
		data->sp_w = abs((int)(data->wd_h / (ty)));
		s = get_startx(data->sp_w, data->sp);
		while (s < get_endx(data->sp_w, data->sp, data))
		{
			if (ty > 0 && s > 0 && s < data->wd_w && ty < zbuf[s])
			{
				ft_sprite_display(ty, data, txtsp, s);
			}
			s++;
		}
		i++;
	}
}
