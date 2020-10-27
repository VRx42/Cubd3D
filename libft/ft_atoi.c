/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:52:24 by vronchin          #+#    #+#             */
/*   Updated: 2020/07/30 12:53:52 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		a;
	int		n;

	n = 1;
	a = 0;
	i = 0;
	while ((str[i] >= 8 && str[i] <= 15) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+' || (str[i] >= 48 && str[i] <= 57))
	{
		if (str[i] == '-')
			n = -1;
		else if (str[i] >= 48 && str[i] <= 57)
			a = str[i] - '0';
		i++;
	}
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		a = (str[i] - '0') + a * 10;
		i++;
	}
	return (a * n);
}
