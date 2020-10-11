/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:07:08 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:07:11 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void    init_texture(t_data *data, t_txt *txt, char *line)
{
    int i;

    i = 2;
    while (line[i] == ' ')
        i++;
    if (!(txt->id  = mlx_xpm_file_to_image(data->mlx, line + i, \
    &txt->height, &txt->width)))
    {
        ft_strdel(&line);
        ft_display_error(data, "Path of texture is wrong!");
    }
	txt->data = (int*)mlx_get_data_addr(txt->id, &txt->bpp, \
    &txt->size_l, &txt->endian);
}
