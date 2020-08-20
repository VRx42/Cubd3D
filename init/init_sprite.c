/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:05:18 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:05:21 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void    init_sprite(t_data *data)
{
    int y;
    int x;
    int i;

    i = 0;
    y = 0;
    x = 0;
    if (data->nbsprite)
    {
        data->tab_sprite = ft_calloc(data->nbsprite, sizeof(t_sprite));
        while (x < data->map_h)
        {
            while (data->map[x][y])
            {
                if (data->map[x][y] == '2')
                {
                    data->tab_sprite[i].x = x + 0.5;
                    data->tab_sprite[i].y = y + 0.5;
                    i++;
                }
                y++;
            }
            y = 0;
            x++;
        }
    }
}
