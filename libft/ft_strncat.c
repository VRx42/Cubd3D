/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:29:04 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/22 17:44:05 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;

	if (ft_strlen(src) < n)
		n = ft_strlen(src);
	i = ft_strlen(dest);
	ft_strncpy(dest + i, src, n);
	dest[i + n] = '\0';
	return (dest);
}
