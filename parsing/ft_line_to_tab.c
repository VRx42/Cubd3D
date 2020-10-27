/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 13:53:10 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/04 17:02:47 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

char	*add_ones(char *str, int w)
{
	int j;

	j = 0;
	while (j < w)
	{
		if (str[j] == ' ')
			str[j] = '1';
		j++;
	}
	return (str);
}

char	*complete_line(char *str, int w)
{
	int		i;
	char	*space;

	space = NULL;
	i = 0;
	if (w > (int)ft_strlen(str))
	{
		space = ft_strnew(w - (int)ft_strlen(str));
		while (i < w - (int)ft_strlen(str))
		{
			space[i] = '1';
			i++;
		}
		return (ft_strjoinplus(str, space, 3));
	}
	return (add_ones(str, w));
}

void	ft_line_to_tab(char *line, t_data *data)
{
	int	i;
	int	b;
	int a;

	a = 0;
	b = 0;
	i = 0;
	data->map = (char**)ft_calloc(data->map_h, sizeof(char*));
	while (line[i])
	{
		if (line[i] == '|')
		{
			data->map[a] = ft_strndup(line + i - b, b);
			data->map[a] = complete_line(data->map[a], data->map_w);
			b = 0;
			i++;
			a++;
		}
		i++;
		b++;
	}
	ft_strdel(&line);
}
