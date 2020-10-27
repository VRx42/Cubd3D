/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 13:46:40 by vronchin          #+#    #+#             */
/*   Updated: 2020/10/12 13:46:42 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static void	s_image(t_data *data, t_bmp *bmp)
{
	int x;
	int y;

	y = data->wd_h - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < data->wd_w)
		{
			bmp->color = 0;
			write(bmp->fd, &bmp->color, 4);
			x++;
		}
		y--;
	}
}

static void	s_encode(char *encode, int value)
{
	encode[0] = (unsigned char)(value);
	encode[1] = (unsigned char)(value >> 8);
	encode[2] = (unsigned char)(value >> 16);
	encode[3] = (unsigned char)(value >> 24);
}

static void	s_header(t_data *data, t_bmp *bmp)
{
	if (!(bmp->header = (char *)ft_calloc(sizeof(char), 54)))
		ft_display_error(data, "    Bitmap: the mallloc failed\
		impossible to make the header [bmp->header].\n");
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	s_encode(&bmp->header[2], 54 + 4 * data->wd_w * data->wd_h);
	bmp->header[10] = 54;
	bmp->header[14] = 40;
	s_encode(&bmp->header[18], data->wd_w);
	s_encode(&bmp->header[22], data->wd_h);
	bmp->header[26] = 1;
	bmp->header[28] = data->img.bpp;
	write(bmp->fd, bmp->header, 54);
}

void		ft_bmp(t_data *data)
{
	t_bmp	bmp;

	if (!(bmp.fd = open("image.bmp", O_CREAT | O_WRONLY, S_IRWXU)))
		ft_display_error(data, "    Bitmap: Unable to create the\
		image.bmp file [bmp.fd].\n");
	s_header(data, &bmp);
	s_image(data, &bmp);
	close(bmp.fd);
	free(bmp.header);
}
