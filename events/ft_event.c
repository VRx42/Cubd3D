/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:08:10 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 18:08:13 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int		ft_event(int keycode, t_data *data)
{
	if (keycode == K_Z)
		ft_move_forward(data);
	else if (keycode == K_S)
		ft_move_back(data);
	else if (keycode == K_Q)
		ft_move_left(data);
	else if (keycode == K_D)
		ft_move_right(data);
	else if (keycode == K_ARRL || keycode == K_ARRR)
		ft_move_cam(data, keycode == K_ARRL ? SPT : -SPT);
	else if (keycode == K_ESC)
		ft_close_window(data);
	else
		return (0);
	ft_put_image(data);
	return (0);
}
