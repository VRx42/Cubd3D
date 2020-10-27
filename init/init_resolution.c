/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_resolution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:06:16 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:06:53 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

static	void	correct_wd_size(t_data *data, char *line)
{
	int sizex;
	int sizey;

	if (!data->wd_h || !data->wd_w)
	{
		ft_strdel(&line);
		ft_display_error(data, "Params for resolution can't be 0");
	}
	mlx_get_screen_size(data->mlx, &sizex, &sizey);
	if (data->wd_w > sizex || data->wd_h > sizey)
	{
		data->wd_w = sizex;
		data->wd_h = sizey;
	}
}

void			check_resolution(t_data *data, char *line)
{
	int i;

	i = 1;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ')
		{
			ft_strdel(&line);
			ft_display_error(data, "Other than digit for resolution");
		}
		i++;
	}
}

void			init_resolution(t_data *data, char *line)
{
	int i;

	check_resolution(data, line);
	i = 1;
	while (line[i] == ' ')
		i++;
	data->wd_w = ft_atoi(line + 1);
	while (ft_isdigit(line[i]))
		i++;
	data->wd_h = ft_atoi(line + i);
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i])
	{
		ft_strdel(&line);
		ft_display_error(data, "More than two params for resolution");
	}
	correct_wd_size(data, line);
}
