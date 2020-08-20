/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 17:31:16 by vronchin          #+#    #+#             */
/*   Updated: 2020/08/20 17:31:34 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    ft_error(t_data *data, char *s)
{
    write(2, "Error : ", 8);
    write(2, s, ft_strlen(s));
    write(2, "\n", 1);
    ft_exit_cub(data);
}