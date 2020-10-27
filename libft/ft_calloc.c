/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vronchin <vronchin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 12:40:00 by vronchin          #+#    #+#             */
/*   Updated: 2020/02/22 17:29:32 by vronchin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*zm;

	if (!(zm = malloc(size * nmemb)))
		return (NULL);
	ft_bzero(zm, size * nmemb);
	return (zm);
}
