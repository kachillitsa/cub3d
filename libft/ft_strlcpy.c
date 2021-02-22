/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:19:14 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 04:19:16 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t size2;

	size2 = size;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (!src[i])
		dst[i] = '\0';
	while ((src[i] != '\0') && (size2 - 1 > 0))
	{
		dst[i] = src[i];
		i++;
		dst[i] = '\0';
		size2--;
	}
	return (ft_strlen(src));
}
