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

int	rgb_to_int(char *str)
{
	int	r;
	int	g;
	int	b;
	int	i;
	int	total;

	i = 0;
	r = ft_atoi(str);
	while (str[i] != ',')
		i++;
	g = ft_atoi(str + i + 1);
	i = i + 1;
	while (str[i] != ',')
		i++;
	b = ft_atoi(str + i + 1);
	total = 256 * 256 * r + 256 * g + b;
	return (total);
}

int	init_color(t_data *data, char *line)
{
	int i;
	int n;

	i = 2;
	if (line[1] != ' ')
	{
		ft_strdel(&line);
		ft_display_error(data, "Params wrong for color(1)");
	}
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',')
		{
			ft_strdel(&line);
			ft_display_error(data, "Params wrong for color(2)");
		}
		i++;
	}
	n = rgb_to_int(line + 1);
	return (n);
}
