/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:04:31 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:04:39 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int    init_color(t_data *data, char *line)
{
    int i;
    int true;

    true = 0;
    i = 2;
    if (line[1] != ' ')
    {
        ft_strdel(&line);
        ft_display_error(data, "Params wrong for color(1)");
    }
    while (line[i])
    {
        ft_isdigit(line[i]) || true ? true = 1 : 0;
        if (!ft_isdigit(line[i]) && line[i] != ' ')
        {
            ft_strdel(&line);
            ft_display_error(data, "Params wrong for color(2)");
        }
        i++;
    }
    i = 1;
    while (line[i] == ' ')
        i++;
    while (ft_isdigit(line[i]))
        i++;
    if (line[i] || !true)
    {
        ft_strdel(&line);
        ft_display_error(data, "Params wrong for color(3)");
    }
	return (ft_atoi(line + 1));
}
