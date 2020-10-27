/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_error.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:31:16 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 17:31:34 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_display_error(t_data *data, char *s)
{
	write(2, "Error encountered : ", 20);
	write(2, s, ft_strlen(s));
	write(2, "\n", 1);
	ft_exit_cube(data);
}
