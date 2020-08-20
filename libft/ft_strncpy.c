
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:05:54 by vronchin          #+#    #+#             */
/*   Updated: 2019/11/22 18:19:35 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	ft_memcpy(dest, src, n);
	while (ft_strlen(src) + i < n)
	{
		dest[ft_strlen(src) + i] = '\0';
		i++;
	}
	return (dest);
}