/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:01:28 by vronchin          #+#    #+#             */
/*   Updated: 2019/01/22 19:01:37 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;

	if (!(dest = ft_strnew(n)))
		return (NULL);
	ft_strncpy(dest, src, n);
	return (dest);
}
