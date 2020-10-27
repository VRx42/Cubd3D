/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 09:07:21 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/22 17:58:41 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*svg;

	if (!dest && !src)
		return (NULL);
	svg = dest;
	while (n--)
		(*(char*)dest++) = (*(char*)src++);
	return (svg);
}
