/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjebedia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:18:58 by bjebedia          #+#    #+#             */
/*   Updated: 2020/07/31 04:18:59 by bjebedia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t			len;
	char			*dup;
	char			*start;

	len = ft_strlen(str);
	if (!(dup = (char *)malloc(sizeof(char) * len + 1)))
		return ((char *)NULL);
	start = dup;
	while (*str)
		*dup++ = *str++;
	*dup = '\0';
	return (start);
}
